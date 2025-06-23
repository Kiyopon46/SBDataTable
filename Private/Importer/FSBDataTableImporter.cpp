#include "Importer/FSBDataTableImporter.h"
#include "Engine/DataTable.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonReader.h"

#include "AssetRegistryModule.h"
#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"

#include "Misc/MessageDialog.h"
#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SWindow.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

#define LOCTEXT_NAMESPACE "FSBDataTableImporter"

void FSBDataTableImporter::Execute()
{
    FString PackagePath = GetPackagePath();

    // Check if the file exists
    UDataTable* ExistingTable = GetExistingTable(PackagePath);

    // If the file exists, confirm overwriting
    if (ExistingTable)
    {
        FText DialogText = FText::FromString(TEXT("The DataTable already exists. Do you want to overwrite it?"));
        EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgType::YesNo, DialogText);

        if (Result == EAppReturnType::No)
        {
            UE_LOG(LogTemp, Log, TEXT("User chose not to overwrite the existing DataTable."));
            return;
        }

        // Delete first if it's okay to overwrite.
        if (ExistingTable)
        {
            FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
            AssetRegistryModule.Get().AssetDeleted(ExistingTable);
            ExistingTable->MarkPendingKill();
            ExistingTable->GetOutermost()->MarkPackageDirty();
            ExistingTable->ConditionalBeginDestroy();
        }
    }

    FString JsonPath = GetJsonFilePath();
    if (JsonPath.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("GetJsonFilePath() failed."));
        return;
    }

    TSharedPtr<FJsonObject> RowsObject = LoadJsonRows(JsonPath);
    if (!RowsObject.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("LoadJsonRows() failed."));
        return;
    }

    UDataTable* TargetTable = CreateDataTable();
    if (!TargetTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("CreateCharacterDataTable() failed."));
        return;
    }

    // Read data from JSON and set it in a DataTable.
    PopulateDataTable(TargetTable, RowsObject);

    SaveDataTableAsset(TargetTable, PackagePath);
}

UDataTable* FSBDataTableImporter::GetExistingTable(const FString& PackagePath)
{
    UObject* ExistingAsset = LoadObject<UObject>(nullptr, *PackagePath);
    UDataTable* ExistingTable = Cast<UDataTable>(ExistingAsset);

    return ExistingTable;
}

FString FSBDataTableImporter::GetJsonFilePath()
{
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (!DesktopPlatform)
    {
        FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Desktop platform not available.")));
        return FString(TEXT(""));
    }

    const void* ParentWindowHandle = nullptr;
    if (FSlateApplication::IsInitialized())
    {
        TSharedPtr<SWindow> ParentWindow = nullptr;
        ParentWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(ParentWindow);
    }

    TArray<FString> OutFiles;
    bool bOpened = DesktopPlatform->OpenFileDialog(
        ParentWindowHandle,
        TEXT("Select JSON File"),
        FPaths::ProjectContentDir(),
        TEXT(""),
        TEXT("JSON files (*.json)|*.json"),
        EFileDialogFlags::None,
        OutFiles
    );

    if (!bOpened || OutFiles.Num() == 0) {
        UE_LOG(LogTemp, Warning, TEXT("!bOpened || OutFiles.Num() == 0 failed."));
        return FString(TEXT(""));
    }

    FString FilePath = OutFiles[0];

    return FilePath;
}

TSharedPtr<FJsonObject> FSBDataTableImporter::LoadJsonRows(const FString& FilePath)
{
    // Loading a JSON file
    FString FileContent;
    if (!FFileHelper::LoadFileToString(FileContent, *FilePath)) {
        UE_LOG(LogTemp, Warning, TEXT("LoadFileToString() failed."));
        return nullptr;
    }

    // If the first character is a BOM, delete it.
    if (FileContent.StartsWith(TEXT("\xFEFF"))) {
        FileContent.RightChopInline(1);  // Delete the first character
    }

    // Create an Array from JSON
    TArray<TSharedPtr<FJsonValue>> RootArray;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FileContent);

    if (!FJsonSerializer::Deserialize(Reader, RootArray) || RootArray.Num() == 0) {
        UE_LOG(LogTemp, Error, TEXT("Failed to parse JSON as array or array is empty."));
        return nullptr;
    }

    // Extract the first element (assuming there is only one object in the array)
    TSharedPtr<FJsonObject> DataTableObject = RootArray[0]->AsObject();
    if (!DataTableObject.IsValid()) {
        UE_LOG(LogTemp, Error, TEXT("First object in array is invalid."));
        return nullptr;
    }

    // Get "Rows" Object
    const TSharedPtr<FJsonObject>* RowsObjectPtr = nullptr;
    if (!DataTableObject->TryGetObjectField(TEXT("Rows"), RowsObjectPtr) || !RowsObjectPtr) {
        UE_LOG(LogTemp, Error, TEXT("Rows field missing or invalid."));
        return nullptr;
    }

    return *RowsObjectPtr;
}

UDataTable* FSBDataTableImporter::CreateDataTable()
{
    // Create Package and DataTable
    UDataTable* DataTable = CreateObject();
    DataTable->RowStruct = GetRowStruct();

    return DataTable;
}

UDataTable* FSBDataTableImporter::CreateObject()
{
    FString PackagePath = GetPackagePath();
    UPackage* Package = CreatePackage(*PackagePath);
    return NewObject<UDataTable>(Package, *FPaths::GetBaseFilename(PackagePath), RF_Public | RF_Transactional | RF_Standalone);
}

void FSBDataTableImporter::SaveDataTableAsset(UDataTable* DataTable, const FString& PackagePath)
{
    if (!DataTable || PackagePath.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveDataTableAsset: Invalid DataTable or PackagePath."));
        return;
    }

    // Register the asset
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    AssetRegistryModule.Get().AssetCreated(DataTable);

    // Mark as dirty
    DataTable->MarkPackageDirty();

    // Convert to full file path
    FString PackageFilePath = FPackageName::LongPackageNameToFilename(PackagePath, FPackageName::GetAssetPackageExtension());

    // Get the outer package from the DataTable
    UPackage* Package = DataTable->GetOutermost();

    if (!Package)
    {
        UE_LOG(LogTemp, Warning, TEXT("SaveDataTableAsset: Failed to get outermost package."));
        return;
    }

    // Save the package
    bool bSuccess = UPackage::SavePackage(
        Package,
        DataTable,
        EObjectFlags::RF_Public | EObjectFlags::RF_Standalone,
        *PackageFilePath,
        GError,
        nullptr,
        true,
        true,
        SAVE_None
    );

    if (bSuccess)
    {
        UE_LOG(LogTemp, Log, TEXT("DataTable saved successfully to %s"), *PackageFilePath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to save DataTable to %s"), *PackageFilePath);
    }
}

#undef LOCTEXT_NAMESPACE

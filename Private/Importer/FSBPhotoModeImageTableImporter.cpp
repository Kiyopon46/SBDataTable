#include "Importer/FSBPhotoModeImageTableImporter.h"
#include "SBPhotoModeImageTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoModeImageTableImporter"

FSBMenuEntry FSBPhotoModeImageTableImporter::GetMenuEntry()
{
    FSBMenuEntry Entry;
    Entry.Name = "PhotoModeImageTableEntry";
    Entry.Label = LOCTEXT("PhotoModeImageTableEntry", "PhotoModeImageTable");
    Entry.Tooltip = LOCTEXT("PhotoModeImageTableEntry_Tooltip", "Run PhotoModeImageTable tool");

    Entry.Callback = [this]()
    {
        this->Execute();
    };

    return Entry;
}

FString FSBPhotoModeImageTableImporter::GetPackagePath() const
{
    return TEXT("/Game/Local/Data/PhotoModeImageTable");
}

UScriptStruct* FSBPhotoModeImageTableImporter::GetRowStruct() const
{
    return FSBPhotoModeImageTableProperty::StaticStruct();
}

void FSBPhotoModeImageTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject)
{
    for (const auto& RowPair : RowsObject->Values) {
        FString RowName = RowPair.Key;

        const TSharedPtr<FJsonObject>* RowDataObjectPtr;
        if (!RowPair.Value->TryGetObject(RowDataObjectPtr) || !RowDataObjectPtr) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid row object for RowName: %s"), *RowName);
            continue;
        }

        const TSharedPtr<FJsonObject>& RowDataObject = *RowDataObjectPtr;

        FSBPhotoModeImageTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UIOperateArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UIOperateArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("OptionStringKey"), RowName, [&](const FString& Val) { NewRow.OptionStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ImagePath"), RowName, [&](const FString& Val) { NewRow.ImagePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnableConditionGroup"), RowName, [&](const FString& Val) { NewRow.EnableConditionGroup = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

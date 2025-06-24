#include "Importer/FSBPhotoModeFacialAnimationTableImporter.h"
#include "SBPhotoModeFacialAnimationTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoModeFacialAnimationTableImporter"

FString FSBPhotoModeFacialAnimationTableImporter::GetDataTableName() const
{
    return "PhotoModeFacialAnimationTable";
}

TFunction<void()> FSBPhotoModeFacialAnimationTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBPhotoModeFacialAnimationTableImporter::GetRowStruct() const
{
    return FSBPhotoModeFacialAnimationTableProperty::StaticStruct();
}

void FSBPhotoModeFacialAnimationTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
{
    // Get "Rows" Object
    const TSharedPtr<FJsonObject>* RowsObjectPtr = nullptr;
    if (!DataTableObject->TryGetObjectField(TEXT("Rows"), RowsObjectPtr) || !RowsObjectPtr) {
        UE_LOG(LogTemp, Error, TEXT("Rows field missing or invalid."));
        return;
    }

    const TSharedPtr<FJsonObject>& RowsObject = *RowsObjectPtr;
    for (const auto& RowPair : RowsObject->Values) {
        FString RowName = RowPair.Key;

        const TSharedPtr<FJsonObject>* RowDataObjectPtr;
        if (!RowPair.Value->TryGetObject(RowDataObjectPtr) || !RowDataObjectPtr) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid row object for RowName: %s"), *RowName);
            continue;
        }

        const TSharedPtr<FJsonObject>& RowDataObject = *RowDataObjectPtr;

        FSBPhotoModeFacialAnimationTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhotoModeTag"), RowName, [&](const FString& Val) { NewRow.PhotoModeTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("CameraType"), RowName, [&](const FString& Val) { NewRow.CameraType = Val; });
        TryApplyStringField(RowDataObject, TEXT("AssetPath"), RowName, [&](const FString& Val) { NewRow.AssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("EyesPosition"), RowName, [&](const FString& Val) { NewRow.EyesPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

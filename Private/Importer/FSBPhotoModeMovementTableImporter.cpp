#include "Importer/FSBPhotoModeMovementTableImporter.h"
#include "SBPhotoModeMovementTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoModeMovementTableImporter"

FString FSBPhotoModeMovementTableImporter::GetDataTableName() const
{
    return "PhotoModeMovementTable";
}

TFunction<void()> FSBPhotoModeMovementTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBPhotoModeMovementTableImporter::GetRowStruct() const
{
    return FSBPhotoModeMovementTableProperty::StaticStruct();
}

void FSBPhotoModeMovementTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBPhotoModeMovementTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputDirection"), RowName, [&](const FString& Val) { NewRow.InputDirection = Val; });
        TryApplyStringField(RowDataObject, TEXT("CameraType"), RowName, [&](const FString& Val) { NewRow.CameraType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Acceleration"), RowName, [&](float Val) { NewRow.Acceleration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Deceleration"), RowName, [&](float Val) { NewRow.Deceleration = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAffectedByFOV"), RowName, [&](bool Val) { NewRow.bAffectedByFOV = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FOVScaleMin"), RowName, [&](float Val) { NewRow.FOVScaleMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FOVScaleMax"), RowName, [&](float Val) { NewRow.FOVScaleMax = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

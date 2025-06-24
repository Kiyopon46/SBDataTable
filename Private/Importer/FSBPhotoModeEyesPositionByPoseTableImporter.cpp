#include "Importer/FSBPhotoModeEyesPositionByPoseTableImporter.h"
#include "SBPhotoModeEyesPositionByPoseProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoModeEyesPositionByPoseTableImporter"

FString FSBPhotoModeEyesPositionByPoseTableImporter::GetDataTableName() const
{
    return "PhotoModeEyesPositionByPoseTable";
}

TFunction<void()> FSBPhotoModeEyesPositionByPoseTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBPhotoModeEyesPositionByPoseTableImporter::GetRowStruct() const
{
    return FSBPhotoModeEyesPositionByPoseProperty::StaticStruct();
}

void FSBPhotoModeEyesPositionByPoseTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBPhotoModeEyesPositionByPoseProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("PoseName"), RowName, [&](const FString& Val) { NewRow.PoseName = Val; });
        TryApplyStringField(RowDataObject, TEXT("CameraType"), RowName, [&](const FString& Val) { NewRow.CameraType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EyesPosition"), RowName, [&](const FString& Val) { NewRow.EyesPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EyesPosition_Adam"), RowName, [&](const FString& Val) { NewRow.EyesPosition_Adam = Val; });
        TryApplyStringField(RowDataObject, TEXT("EyesPosition_Lily"), RowName, [&](const FString& Val) { NewRow.EyesPosition_Lily = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

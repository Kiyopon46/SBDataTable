#include "Importer/FSBEventZoneWarpTableImporter.h"
#include "SBEventZoneWarpTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventZoneWarpTableImporter"

FString FSBEventZoneWarpTableImporter::GetDataTableName() const
{
    return "EventZoneWarpTable";
}

TFunction<void()> FSBEventZoneWarpTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventZoneWarpTableImporter::GetRowStruct() const
{
    return FSBEventZoneWarpTableProperty::StaticStruct();
}

void FSBEventZoneWarpTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventZoneWarpTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetWorld"), RowName, [&](const FString& Val) { NewRow.TargetWorld = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetZoneCamp"), RowName, [&](const FString& Val) { NewRow.TargetZoneCamp = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetSpawnPoint"), RowName, [&](const FString& Val) { NewRow.TargetSpawnPoint = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetLocation"), RowName, [&](const FString& Val) { NewRow.TargetLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRotation"), RowName, [&](const FString& Val) { NewRow.TargetRotation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseRecoveryItems"), RowName, [&](bool Val) { NewRow.bUseRecoveryItems = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WarpDelayTime"), RowName, [&](float Val) { NewRow.WarpDelayTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FadeOutTime"), RowName, [&](float Val) { NewRow.FadeOutTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseCampCustomTargetPoint"), RowName, [&](bool Val) { NewRow.bUseCampCustomTargetPoint = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

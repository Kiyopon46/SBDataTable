#include "Importer/FSBTrainingRoomSettingTableImporter.h"
#include "SBTrainningRoomSettingTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBTrainingRoomSettingTableImporter"

FString FSBTrainingRoomSettingTableImporter::GetDataTableName() const
{
    return "TrainingRoomSettingTable";
}

TFunction<void()> FSBTrainingRoomSettingTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBTrainingRoomSettingTableImporter::GetRowStruct() const
{
    return FSBTrainningRoomSettingTableProperty::StaticStruct();
}

void FSBTrainingRoomSettingTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBTrainningRoomSettingTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Zone"), RowName, [&](const FString& Val) { NewRow.Zone = Val; });
        TryApplyStringField(RowDataObject, TEXT("RegionActorName"), RowName, [&](const FString& Val) { NewRow.RegionActorName = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitRegionActorEvent"), RowName, [&](const FString& Val) { NewRow.InitRegionActorEvent = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bInitApplyPlayerInfiniteEffect"), RowName, [&](bool Val) { NewRow.bInitApplyPlayerInfiniteEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("PlayerStartPoint"), RowName, [&](const FString& Val) { NewRow.PlayerStartPoint = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("PlayerStartEffects"), RowName, [&](const TArray<FString>& Val) { NewRow.PlayerStartEffects = Val; });
        TryApplyStringField(RowDataObject, TEXT("PlayerStartSkill"), RowName, [&](const FString& Val) { NewRow.PlayerStartSkill = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnemyStartEffects"), RowName, [&](const TArray<FString>& Val) { NewRow.EnemyStartEffects = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnemyNpcAIType"), RowName, [&](const FString& Val) { NewRow.EnemyNpcAIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnemyNpcSpawnPointPreFix"), RowName, [&](const FString& Val) { NewRow.EnemyNpcSpawnPointPreFix = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnemyNpcReSpawnPointPreFix"), RowName, [&](const FString& Val) { NewRow.EnemyNpcReSpawnPointPreFix = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnemySpawnList"), RowName, [&](const TArray<FString>& Val) { NewRow.EnemySpawnList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnemySpawnRotationTypeList"), RowName, [&](const TArray<FString>& Val) { NewRow.EnemySpawnRotationTypeList = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

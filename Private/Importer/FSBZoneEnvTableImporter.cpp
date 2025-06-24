#include "Importer/FSBZoneEnvTableImporter.h"
#include "SBZoneEnvTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneEnvTableImporter"

FString FSBZoneEnvTableImporter::GetDataTableName() const
{
    return "ZoneEnvTable";
}

TFunction<void()> FSBZoneEnvTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneEnvTableImporter::GetRowStruct() const
{
    return FSBZoneEnvTableProperty::StaticStruct();
}

void FSBZoneEnvTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEnvTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvType"), RowName, [&](const FString& Val) { NewRow.EnvType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateTagNameList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateTagNameList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateEffectList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateEffectList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateZoneEventList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateZoneEventList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateConditionGroupList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateConditionGroupList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateRewardGroupList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateRewardGroupList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateCasterShowPathList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateCasterShowPathList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateProgressCountList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateProgressCountList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StateProgressChangeTagNameList"), RowName, [&](const TArray<FString>& Val) { NewRow.StateProgressChangeTagNameList = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnBucketType"), RowName, [&](const FString& Val) { NewRow.RewardSpawnBucketType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardOverrideSaveType"), RowName, [&](const FString& Val) { NewRow.RewardOverrideSaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnFormationAsset"), RowName, [&](const FString& Val) { NewRow.RewardSpawnFormationAsset = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvObjectMaterial"), RowName, [&](const FString& Val) { NewRow.EnvObjectMaterial = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseAutoActivateCamp"), RowName, [&](bool Val) { NewRow.bUseAutoActivateCamp = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveEnterEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveEnterEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveLeaveEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveLeaveEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProgressMaxValue"), RowName, [&](const TArray<FString>& Val) { NewRow.ProgressMaxValue = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("bProgressAlwaysUpdates"), RowName, [&](const TArray<FString>& Val) { NewRow.bProgressAlwaysUpdates = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProgressNotifyEventList"), RowName, [&](const TArray<FString>& Val) { NewRow.ProgressNotifyEventList = Val; });
        TryApplyIntField(RowDataObject, TEXT("TriggerCount"), RowName, [&](int32 Val) { NewRow.TriggerCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("TriggerCondition"), RowName, [&](const FString& Val) { NewRow.TriggerCondition = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TriggerTrueEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.TriggerTrueEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TriggerFalseEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.TriggerFalseEvents = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrueEnvState"), RowName, [&](const FString& Val) { NewRow.TrueEnvState = Val; });
        TryApplyStringField(RowDataObject, TEXT("FalseEnvState"), RowName, [&](const FString& Val) { NewRow.FalseEnvState = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionRange"), RowName, [&](float Val) { NewRow.InteractionRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionUpperHeight"), RowName, [&](float Val) { NewRow.InteractionUpperHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionLowerHeight"), RowName, [&](float Val) { NewRow.InteractionLowerHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionAngle"), RowName, [&](float Val) { NewRow.InteractionAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionTargetRange"), RowName, [&](float Val) { NewRow.InteractionTargetRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionDotUIAngle"), RowName, [&](float Val) { NewRow.InteractionDotUIAngle = Val; });
        TryApplyStringField(RowDataObject, TEXT("Interaction"), RowName, [&](const FString& Val) { NewRow.Interaction = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bForceFoldInteraction"), RowName, [&](bool Val) { NewRow.bForceFoldInteraction = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampType"), RowName, [&](const FString& Val) { NewRow.CampType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampObjectType"), RowName, [&](const FString& Val) { NewRow.CampObjectType = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleCompareData"), RowName, [&](const FString& Val) { NewRow.PuzzleCompareData = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleDataType"), RowName, [&](const FString& Val) { NewRow.PuzzleDataType = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleEq"), RowName, [&](const FString& Val) { NewRow.PuzzleEq = Val; });
        TryApplyStringField(RowDataObject, TEXT("ScanDisplayType"), RowName, [&](const FString& Val) { NewRow.ScanDisplayType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("NikkeGoodsDetectDistance_Max"), RowName, [&](float Val) { NewRow.NikkeGoodsDetectDistance_Max = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("NikkeDefenseArea_EnemyEnter_Events"), RowName, [&](const TArray<FString>& Val) { NewRow.NikkeDefenseArea_EnemyEnter_Events = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("NikkeDefenseArea_EnemyEmpty_Events"), RowName, [&](const TArray<FString>& Val) { NewRow.NikkeDefenseArea_EnemyEmpty_Events = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

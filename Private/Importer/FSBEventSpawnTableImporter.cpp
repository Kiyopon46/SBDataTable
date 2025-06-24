#include "Importer/FSBEventSpawnTableImporter.h"
#include "SBZoneEventSpawnTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventSpawnTableImporter"

FString FSBEventSpawnTableImporter::GetDataTableName() const
{
    return "EventSpawnTable";
}

TFunction<void()> FSBEventSpawnTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventSpawnTableImporter::GetRowStruct() const
{
    return FSBZoneEventSpawnTableProperty::StaticStruct();
}

void FSBEventSpawnTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventSpawnTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnPointName"), RowName, [&](const FString& Val) { NewRow.SpawnPointName = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitActivate"), RowName, [&](const FString& Val) { NewRow.InitActivate = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CharacterAlias"), RowName, [&](const TArray<FString>& Val) { NewRow.CharacterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnType"), RowName, [&](const FString& Val) { NewRow.SpawnType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnRotationType"), RowName, [&](const FString& Val) { NewRow.SpawnRotationType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Zone"), RowName, [&](const FString& Val) { NewRow.Zone = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnGroupRuleAlias"), RowName, [&](const FString& Val) { NewRow.SpawnGroupRuleAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveSubProperty"), RowName, [&](const FString& Val) { NewRow.SaveSubProperty = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bResetZoneKeepObject"), RowName, [&](bool Val) { NewRow.bResetZoneKeepObject = Val; });
        TryApplyStringField(RowDataObject, TEXT("KeepObjResetTransformType"), RowName, [&](const FString& Val) { NewRow.KeepObjResetTransformType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepObjApplyResetState"), RowName, [&](bool Val) { NewRow.bKeepObjApplyResetState = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSaveWithBlackBoard"), RowName, [&](bool Val) { NewRow.bSaveWithBlackBoard = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSpawnToActive"), RowName, [&](bool Val) { NewRow.bSpawnToActive = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DrawDistance"), RowName, [&](float Val) { NewRow.DrawDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableDrawDistanceScale"), RowName, [&](bool Val) { NewRow.bDisableDrawDistanceScale = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AlwaysTickDistance"), RowName, [&](float Val) { NewRow.AlwaysTickDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepSBCharacterWhenActiveAreaControlVolume"), RowName, [&](bool Val) { NewRow.bKeepSBCharacterWhenActiveAreaControlVolume = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EventOnSpawning"), RowName, [&](const TArray<FString>& Val) { NewRow.EventOnSpawning = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EventOnDead"), RowName, [&](const TArray<FString>& Val) { NewRow.EventOnDead = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EventOnBattle"), RowName, [&](const TArray<FString>& Val) { NewRow.EventOnBattle = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EventFirstTimeOnBattle"), RowName, [&](const TArray<FString>& Val) { NewRow.EventFirstTimeOnBattle = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnShow"), RowName, [&](const FString& Val) { NewRow.SpawnShow = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableActorTickAtSpawning"), RowName, [&](bool Val) { NewRow.bEnableActorTickAtSpawning = Val; });
        TryApplyBoolField(RowDataObject, TEXT("GoPathAfterSpawn"), RowName, [&](bool Val) { NewRow.GoPathAfterSpawn = Val; });
        TryApplyStringField(RowDataObject, TEXT("PathWay"), RowName, [&](const FString& Val) { NewRow.PathWay = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardGroup"), RowName, [&](const FString& Val) { NewRow.RewardGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnBucketType"), RowName, [&](const FString& Val) { NewRow.RewardSpawnBucketType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardOverrideSaveType"), RowName, [&](const FString& Val) { NewRow.RewardOverrideSaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("TagName"), RowName, [&](const FString& Val) { NewRow.TagName = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bHidden"), RowName, [&](bool Val) { NewRow.bHidden = Val; });
        TryApplyStringField(RowDataObject, TEXT("AIGroupAlias"), RowName, [&](const FString& Val) { NewRow.AIGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AIGroupName"), RowName, [&](const FString& Val) { NewRow.AIGroupName = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAIGroupLeader"), RowName, [&](bool Val) { NewRow.bAIGroupLeader = Val; });
        TryApplyStringField(RowDataObject, TEXT("MetaAIAlias"), RowName, [&](const FString& Val) { NewRow.MetaAIAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("MetaAI_InitThink"), RowName, [&](const FString& Val) { NewRow.MetaAI_InitThink = Val; });
        TryApplyStringField(RowDataObject, TEXT("MetaAI_SpecialBehaviorTag"), RowName, [&](const FString& Val) { NewRow.MetaAI_SpecialBehaviorTag = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionRange"), RowName, [&](float Val) { NewRow.InteractionRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionAngle"), RowName, [&](float Val) { NewRow.InteractionAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionTargetRange"), RowName, [&](float Val) { NewRow.InteractionTargetRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionDotUIAngle"), RowName, [&](float Val) { NewRow.InteractionDotUIAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionUpperHeight"), RowName, [&](float Val) { NewRow.InteractionUpperHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionLowerHeight"), RowName, [&](float Val) { NewRow.InteractionLowerHeight = Val; });
        TryApplyStringField(RowDataObject, TEXT("OwnerRotationType"), RowName, [&](const FString& Val) { NewRow.OwnerRotationType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableTransitZone"), RowName, [&](bool Val) { NewRow.bEnableTransitZone = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableTransitZoneByEnemyActor"), RowName, [&](bool Val) { NewRow.bEnableTransitZoneByEnemyActor = Val; });
        TryApplyStringField(RowDataObject, TEXT("TransitStayZoneSaveType"), RowName, [&](const FString& Val) { NewRow.TransitStayZoneSaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("AdjustInteractTargetPosType"), RowName, [&](const FString& Val) { NewRow.AdjustInteractTargetPosType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Interaction"), RowName, [&](const FString& Val) { NewRow.Interaction = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionsTrigger"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionsTrigger = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionTriggerEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionTriggerEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionTriggerRunType"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionTriggerRunType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionTriggerExecType"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionTriggerExecType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckAchievements"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckAchievements = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("bCheckAchievementNotOperate"), RowName, [&](const TArray<FString>& Val) { NewRow.bCheckAchievementNotOperate = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckAchievementProgress"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckAchievementProgress = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ShopDataList"), RowName, [&](const TArray<FString>& Val) { NewRow.ShopDataList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("SpawnEffectList"), RowName, [&](const TArray<FString>& Val) { NewRow.SpawnEffectList = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnRuleType"), RowName, [&](const FString& Val) { NewRow.SpawnRuleType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RespawnIntervalTimeMin"), RowName, [&](float Val) { NewRow.RespawnIntervalTimeMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RespawnIntervalTimeMax"), RowName, [&](float Val) { NewRow.RespawnIntervalTimeMax = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText1"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText2"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText3"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText4"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText4 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("PuzzleInputTextList5"), RowName, [&](const TArray<FString>& Val) { NewRow.PuzzleInputTextList5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnPosition"), RowName, [&](const FString& Val) { NewRow.SpawnPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayType"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayType = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayTitle"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayTitle = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayDesc"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayDesc = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayConditionGroup"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapIconTag"), RowName, [&](const FString& Val) { NewRow.WorldMapIconTag = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WorldMapOverlapDistance"), RowName, [&](float Val) { NewRow.WorldMapOverlapDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideCustomTrackNearDistance"), RowName, [&](float Val) { NewRow.OverrideCustomTrackNearDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DontCheckZAxisCustomTrackNear"), RowName, [&](bool Val) { NewRow.DontCheckZAxisCustomTrackNear = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionRelevantType"), RowName, [&](const FString& Val) { NewRow.InteractionRelevantType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ObjectMaterial"), RowName, [&](const FString& Val) { NewRow.ObjectMaterial = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("InteractionDisable_Condition"), RowName, [&](const TArray<FString>& Val) { NewRow.InteractionDisable_Condition = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionDisable_ConditionGroup"), RowName, [&](const FString& Val) { NewRow.InteractionDisable_ConditionGroup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMultiSpawnPoint"), RowName, [&](bool Val) { NewRow.bMultiSpawnPoint = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

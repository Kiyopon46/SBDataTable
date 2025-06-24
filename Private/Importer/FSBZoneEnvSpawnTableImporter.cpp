#include "Importer/FSBZoneEnvSpawnTableImporter.h"
#include "SBZoneEnvSpawnTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneEnvSpawnTableImporter"

FString FSBZoneEnvSpawnTableImporter::GetDataTableName() const
{
    return "ZoneEnvSpawnTable";
}

TFunction<void()> FSBZoneEnvSpawnTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneEnvSpawnTableImporter::GetRowStruct() const
{
    return FSBZoneEnvSpawnTableProperty::StaticStruct();
}

void FSBZoneEnvSpawnTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEnvSpawnTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Zone"), RowName, [&](const FString& Val) { NewRow.Zone = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ZoneList"), RowName, [&](const TArray<FString>& Val) { NewRow.ZoneList = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvActorName"), RowName, [&](const FString& Val) { NewRow.EnvActorName = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvBPPath"), RowName, [&](const FString& Val) { NewRow.EnvBPPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnPointName"), RowName, [&](const FString& Val) { NewRow.SpawnPointName = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnConditionGroup"), RowName, [&](const FString& Val) { NewRow.SpawnConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvAlias"), RowName, [&](const FString& Val) { NewRow.EnvAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitActivate"), RowName, [&](const FString& Val) { NewRow.InitActivate = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitEnvActiveState"), RowName, [&](const FString& Val) { NewRow.InitEnvActiveState = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitStateTag"), RowName, [&](const FString& Val) { NewRow.InitStateTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName1"), RowName, [&](const FString& Val) { NewRow.EventTagName1 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList1"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName2"), RowName, [&](const FString& Val) { NewRow.EventTagName2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList2"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName3"), RowName, [&](const FString& Val) { NewRow.EventTagName3 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList3"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName4"), RowName, [&](const FString& Val) { NewRow.EventTagName4 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList4"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName5"), RowName, [&](const FString& Val) { NewRow.EventTagName5 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList5"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName6"), RowName, [&](const FString& Val) { NewRow.EventTagName6 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList6"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName7"), RowName, [&](const FString& Val) { NewRow.EventTagName7 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList7"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName8"), RowName, [&](const FString& Val) { NewRow.EventTagName8 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList8"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName9"), RowName, [&](const FString& Val) { NewRow.EventTagName9 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList9"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventTagName10"), RowName, [&](const FString& Val) { NewRow.EventTagName10 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TagEventList10"), RowName, [&](const TArray<FString>& Val) { NewRow.TagEventList10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName1"), RowName, [&](const FString& Val) { NewRow.RewardTagName1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup1"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName2"), RowName, [&](const FString& Val) { NewRow.RewardTagName2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup2"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName3"), RowName, [&](const FString& Val) { NewRow.RewardTagName3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup3"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName4"), RowName, [&](const FString& Val) { NewRow.RewardTagName4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup4"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName5"), RowName, [&](const FString& Val) { NewRow.RewardTagName5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup5"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName6"), RowName, [&](const FString& Val) { NewRow.RewardTagName6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup6"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName7"), RowName, [&](const FString& Val) { NewRow.RewardTagName7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup7"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName8"), RowName, [&](const FString& Val) { NewRow.RewardTagName8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup8"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName9"), RowName, [&](const FString& Val) { NewRow.RewardTagName9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup9"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardTagName10"), RowName, [&](const FString& Val) { NewRow.RewardTagName10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("State_RewardGroup10"), RowName, [&](const FString& Val) { NewRow.State_RewardGroup10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnFormationAsset"), RowName, [&](const FString& Val) { NewRow.RewardSpawnFormationAsset = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnBucketType"), RowName, [&](const FString& Val) { NewRow.RewardSpawnBucketType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardOverrideSaveType"), RowName, [&](const FString& Val) { NewRow.RewardOverrideSaveType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionRange"), RowName, [&](float Val) { NewRow.InteractionRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionUpperHeight"), RowName, [&](float Val) { NewRow.InteractionUpperHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionLowerHeight"), RowName, [&](float Val) { NewRow.InteractionLowerHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionAngle"), RowName, [&](float Val) { NewRow.InteractionAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionTargetRange"), RowName, [&](float Val) { NewRow.InteractionTargetRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionDotUIAngle"), RowName, [&](float Val) { NewRow.InteractionDotUIAngle = Val; });
        TryApplyStringField(RowDataObject, TEXT("Interaction"), RowName, [&](const FString& Val) { NewRow.Interaction = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveEnterEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveEnterEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveLeaveEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveLeaveEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LinkEnvSpawnList"), RowName, [&](const TArray<FString>& Val) { NewRow.LinkEnvSpawnList = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetCamp"), RowName, [&](const FString& Val) { NewRow.TargetCamp = Val; });
        TryApplyIntField(RowDataObject, TEXT("TriggerCount"), RowName, [&](int32 Val) { NewRow.TriggerCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("TriggerCondition"), RowName, [&](const FString& Val) { NewRow.TriggerCondition = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TriggerTrueEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.TriggerTrueEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TriggerFalseEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.TriggerFalseEvents = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrueEnvState"), RowName, [&](const FString& Val) { NewRow.TrueEnvState = Val; });
        TryApplyStringField(RowDataObject, TEXT("FalseEnvState"), RowName, [&](const FString& Val) { NewRow.FalseEnvState = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("InitProgressValue"), RowName, [&](const TArray<FString>& Val) { NewRow.InitProgressValue = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StartProgressValue"), RowName, [&](const TArray<FString>& Val) { NewRow.StartProgressValue = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EndProgressValue"), RowName, [&](const TArray<FString>& Val) { NewRow.EndProgressValue = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProgressNotifyEventList"), RowName, [&](const TArray<FString>& Val) { NewRow.ProgressNotifyEventList = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description"), RowName, [&](const FString& Val) { NewRow.Description = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleCompareData"), RowName, [&](const FString& Val) { NewRow.PuzzleCompareData = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleDataType"), RowName, [&](const FString& Val) { NewRow.PuzzleDataType = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleEq"), RowName, [&](const FString& Val) { NewRow.PuzzleEq = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText1"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText2"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText3"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PuzzleInputText4"), RowName, [&](const FString& Val) { NewRow.PuzzleInputText4 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("PuzzleInputTextList5"), RowName, [&](const TArray<FString>& Val) { NewRow.PuzzleInputTextList5 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("SequenceTagNameList"), RowName, [&](const TArray<FString>& Val) { NewRow.SequenceTagNameList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("OutTransitTheaterList"), RowName, [&](const TArray<FString>& Val) { NewRow.OutTransitTheaterList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("OutTransitSequenceList"), RowName, [&](const TArray<FString>& Val) { NewRow.OutTransitSequenceList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("OutTransitTemplatePath"), RowName, [&](const TArray<FString>& Val) { NewRow.OutTransitTemplatePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("OutTransitAttachTagNames"), RowName, [&](const TArray<FString>& Val) { NewRow.OutTransitAttachTagNames = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveTheaterList"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveTheaterList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveSequenceList"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveSequenceList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveTemplatePath"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveTemplatePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveAttachTagNames"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveAttachTagNames = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LoopSequenceList"), RowName, [&](const TArray<FString>& Val) { NewRow.LoopSequenceList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LoopTemplatePath"), RowName, [&](const TArray<FString>& Val) { NewRow.LoopTemplatePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LoopAttachTagNames"), RowName, [&](const TArray<FString>& Val) { NewRow.LoopAttachTagNames = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ForceLoopStopWhenChangeState"), RowName, [&](const TArray<FString>& Val) { NewRow.ForceLoopStopWhenChangeState = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DontStopLoopSequenceAtDestoryOptionList"), RowName, [&](const TArray<FString>& Val) { NewRow.DontStopLoopSequenceAtDestoryOptionList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UseTemplateTransformList"), RowName, [&](const TArray<FString>& Val) { NewRow.UseTemplateTransformList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ToTargetStateInfoList"), RowName, [&](const TArray<FString>& Val) { NewRow.ToTargetStateInfoList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("PlayTransformOwnerTypeList"), RowName, [&](const TArray<FString>& Val) { NewRow.PlayTransformOwnerTypeList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ShopDataList"), RowName, [&](const TArray<FString>& Val) { NewRow.ShopDataList = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnPosition"), RowName, [&](const FString& Val) { NewRow.SpawnPosition = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bResetByWarpSafeLocation"), RowName, [&](bool Val) { NewRow.bResetByWarpSafeLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResetFilterType"), RowName, [&](const FString& Val) { NewRow.ResetFilterType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResetFilterCondition"), RowName, [&](const FString& Val) { NewRow.ResetFilterCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayType"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayType = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayTitle"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayTitle = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayDesc"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayDesc = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapDisplayConditionGroup"), RowName, [&](const FString& Val) { NewRow.WorldMapDisplayConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldMapIconTag"), RowName, [&](const FString& Val) { NewRow.WorldMapIconTag = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WorldMapOverlapDistance"), RowName, [&](float Val) { NewRow.WorldMapOverlapDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideCustomTrackNearDistance"), RowName, [&](float Val) { NewRow.OverrideCustomTrackNearDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DontCheckZAxisCustomTrackNear"), RowName, [&](bool Val) { NewRow.DontCheckZAxisCustomTrackNear = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionRelevantType"), RowName, [&](const FString& Val) { NewRow.InteractionRelevantType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMaintainNewGamePlus"), RowName, [&](bool Val) { NewRow.bMaintainNewGamePlus = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SaveMinIntervalByAutoActivateCamp"), RowName, [&](float Val) { NewRow.SaveMinIntervalByAutoActivateCamp = Val; });
        TryApplyStringField(RowDataObject, TEXT("ScanOverrideStencilValue"), RowName, [&](const FString& Val) { NewRow.ScanOverrideStencilValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideNikkeGoodsDetectDistanceMax"), RowName, [&](float Val) { NewRow.OverrideNikkeGoodsDetectDistanceMax = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("InteractionDisable_Condition"), RowName, [&](const TArray<FString>& Val) { NewRow.InteractionDisable_Condition = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionDisable_ConditionGroup"), RowName, [&](const FString& Val) { NewRow.InteractionDisable_ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("NikkeLostArticle"), RowName, [&](const FString& Val) { NewRow.NikkeLostArticle = Val; });
        TryApplyStringField(RowDataObject, TEXT("NikkeFriendlyNpc"), RowName, [&](const FString& Val) { NewRow.NikkeFriendlyNpc = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

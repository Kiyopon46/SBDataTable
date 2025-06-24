#include "Importer/FSBEffectTableImporter.h"
#include "SBEffectTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEffectTableImporter"

FString FSBEffectTableImporter::GetDataTableName() const
{
    return "EffectTable";
}

TFunction<void()> FSBEffectTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEffectTableImporter::GetRowStruct() const
{
    return FSBEffectTableProperty::StaticStruct();
}

void FSBEffectTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEffectTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Flag"), RowName, [&](const FString& Val) { NewRow.Flag = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DispelFlagsArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DispelFlagsArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Tags"), RowName, [&](const TArray<FString>& Val) { NewRow.Tags = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideTribe"), RowName, [&](const FString& Val) { NewRow.OverrideTribe = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectGroupName"), RowName, [&](const FString& Val) { NewRow.EffectGroupName = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectAttributeType"), RowName, [&](const FString& Val) { NewRow.EffectAttributeType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectAttackType"), RowName, [&](const FString& Val) { NewRow.EffectAttackType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionDelay_Jump"), RowName, [&](const FString& Val) { NewRow.ConditionDelay_Jump = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionDelay_Swimming"), RowName, [&](const FString& Val) { NewRow.ConditionDelay_Swimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionDelay_Down"), RowName, [&](const FString& Val) { NewRow.ConditionDelay_Down = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionDelay_Airborne"), RowName, [&](const FString& Val) { NewRow.ConditionDelay_Airborne = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionDelay_KnockBack"), RowName, [&](const FString& Val) { NewRow.ConditionDelay_KnockBack = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ConditionActive_ChancePercent"), RowName, [&](float Val) { NewRow.ConditionActive_ChancePercent = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_Swimming"), RowName, [&](const FString& Val) { NewRow.ConditionActive_Swimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_UnderWater"), RowName, [&](const FString& Val) { NewRow.ConditionActive_UnderWater = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_Airborne"), RowName, [&](const FString& Val) { NewRow.ConditionActive_Airborne = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_Jump"), RowName, [&](const FString& Val) { NewRow.ConditionActive_Jump = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_BattleMode"), RowName, [&](const FString& Val) { NewRow.ConditionActive_BattleMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_TargetType"), RowName, [&](const FString& Val) { NewRow.ConditionActive_TargetType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActiveActorState1"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActiveActorState1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActiveActorState2"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActiveActorState2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActiveActorState3"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActiveActorState3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_DeactiveActorState1"), RowName, [&](const FString& Val) { NewRow.ConditionActive_DeactiveActorState1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_DeactiveActorState2"), RowName, [&](const FString& Val) { NewRow.ConditionActive_DeactiveActorState2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_DeactiveActorState3"), RowName, [&](const FString& Val) { NewRow.ConditionActive_DeactiveActorState3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActorType1"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActorType1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActorType2"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActorType2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActorType3"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActorType3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActorStat1"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActorStat1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ActorStatCheck1"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ActorStatCheck1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConditionActive_ActorStatCheckValue1"), RowName, [&](int32 Val) { NewRow.ConditionActive_ActorStatCheckValue1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ConditionActive_MinAngleFromConstructor"), RowName, [&](float Val) { NewRow.ConditionActive_MinAngleFromConstructor = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ConditionActive_MaxAngleFromConstructor"), RowName, [&](float Val) { NewRow.ConditionActive_MaxAngleFromConstructor = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckNoneEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckNoneEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ConstructorActorAcquisitionAlias"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ConstructorActorAcquisitionAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_DeactiveConstructorActorAcquisitionAlias"), RowName, [&](const FString& Val) { NewRow.ConditionActive_DeactiveConstructorActorAcquisitionAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_MainActorAcquisitionAlias"), RowName, [&](const FString& Val) { NewRow.ConditionActive_MainActorAcquisitionAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_DeactiveMainActorAcquisitionAlias"), RowName, [&](const FString& Val) { NewRow.ConditionActive_DeactiveMainActorAcquisitionAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_ActiveTribe"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_ActiveTribe = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_DeactiveTribe"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_DeactiveTribe = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckCharacterRankArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckCharacterRankArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckNoneCharacterRankArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckNoneCharacterRankArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckCharacterFlagAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckCharacterFlagAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckNoneCharacterFlagAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckNoneCharacterFlagAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_CheckEffectSkillFlagArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_CheckEffectSkillFlagArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_ConstructorEffectActiveTag"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_ConstructorEffectActiveTag = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionActive_ConstructorEffectDeactiveTag"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionActive_ConstructorEffectDeactiveTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_SkillHitResult"), RowName, [&](const FString& Val) { NewRow.ConditionActive_SkillHitResult = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_StoryMode"), RowName, [&](const FString& Val) { NewRow.ConditionActive_StoryMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_EventMove"), RowName, [&](const FString& Val) { NewRow.ConditionActive_EventMove = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ItemAlias"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ItemAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionActive_ItemCompare"), RowName, [&](const FString& Val) { NewRow.ConditionActive_ItemCompare = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConditionActive_ItemCount"), RowName, [&](int32 Val) { NewRow.ConditionActive_ItemCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatType"), RowName, [&](const FString& Val) { NewRow.StatType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatSecondCategory"), RowName, [&](const FString& Val) { NewRow.StatSecondCategory = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType"), RowName, [&](const FString& Val) { NewRow.StatCalculationType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationTarget"), RowName, [&](const FString& Val) { NewRow.StatCalculationTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CalculationValue"), RowName, [&](float Val) { NewRow.CalculationValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CalculationValueRandomMin"), RowName, [&](float Val) { NewRow.CalculationValueRandomMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CalculationValueRandomMax"), RowName, [&](float Val) { NewRow.CalculationValueRandomMax = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CalculationMultipleWhenBacksideHit"), RowName, [&](float Val) { NewRow.CalculationMultipleWhenBacksideHit = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CalculationMultipleValue"), RowName, [&](float Val) { NewRow.CalculationMultipleValue = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAdditionalCalculationWithShield"), RowName, [&](bool Val) { NewRow.bAdditionalCalculationWithShield = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAdditionalCalculationWithCritical"), RowName, [&](bool Val) { NewRow.bAdditionalCalculationWithCritical = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAdditionalCalculationWithAttribute"), RowName, [&](bool Val) { NewRow.bAdditionalCalculationWithAttribute = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAdditionalCalculationWithRange"), RowName, [&](bool Val) { NewRow.bAdditionalCalculationWithRange = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAdditionalCalculationWithWeakPoint"), RowName, [&](bool Val) { NewRow.bAdditionalCalculationWithWeakPoint = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDrainHpByAttack"), RowName, [&](bool Val) { NewRow.bDrainHpByAttack = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBetaGaugeEventByDamage"), RowName, [&](bool Val) { NewRow.bBetaGaugeEventByDamage = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bTachyGaugeEventByDamage"), RowName, [&](bool Val) { NewRow.bTachyGaugeEventByDamage = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bNotGainTachyGaugeByDamage"), RowName, [&](bool Val) { NewRow.bNotGainTachyGaugeByDamage = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bNotVisibleHPBarWhenDamage"), RowName, [&](bool Val) { NewRow.bNotVisibleHPBarWhenDamage = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStatRestore"), RowName, [&](bool Val) { NewRow.bStatRestore = Val; });
        TryApplyStringField(RowDataObject, TEXT("Overlap"), RowName, [&](const FString& Val) { NewRow.Overlap = Val; });
        TryApplyIntField(RowDataObject, TEXT("OverlapCount"), RowName, [&](int32 Val) { NewRow.OverlapCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("LifeType"), RowName, [&](const FString& Val) { NewRow.LifeType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LifeTime"), RowName, [&](float Val) { NewRow.LifeTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartDelayTime"), RowName, [&](float Val) { NewRow.StartDelayTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LoopIntervalTime"), RowName, [&](float Val) { NewRow.LoopIntervalTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FixedTime"), RowName, [&](const TArray<FString>& Val) { NewRow.FixedTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.ActiveTargetFilterAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveTargetEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveTargetEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveTargetResultShowPath"), RowName, [&](const FString& Val) { NewRow.ActiveTargetResultShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bActiveTargetApplyConditionHitMe"), RowName, [&](bool Val) { NewRow.bActiveTargetApplyConditionHitMe = Val; });
        TryApplyStringField(RowDataObject, TEXT("LoopTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.LoopTargetFilterAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LoopTargetEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.LoopTargetEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("LoopTargetResultShowPath"), RowName, [&](const FString& Val) { NewRow.LoopTargetResultShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLoopTargetApplyConditionHitMe"), RowName, [&](bool Val) { NewRow.bLoopTargetApplyConditionHitMe = Val; });
        TryApplyStringField(RowDataObject, TEXT("FixedTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.FixedTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("DeactiveTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.DeactiveTargetFilterAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeactiveTargetEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DeactiveTargetEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("DeactiveTargetResultShowPath"), RowName, [&](const FString& Val) { NewRow.DeactiveTargetResultShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDeactiveTargetApplyConditionHitMe"), RowName, [&](bool Val) { NewRow.bDeactiveTargetApplyConditionHitMe = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustEvade"), RowName, [&](bool Val) { NewRow.AvailableJustEvade = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepPlayedShowWhenDeactive"), RowName, [&](bool Val) { NewRow.bKeepPlayedShowWhenDeactive = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveShowPath"), RowName, [&](const FString& Val) { NewRow.ActiveShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("LoopShowPath"), RowName, [&](const FString& Val) { NewRow.LoopShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("DeactiveShowPath"), RowName, [&](const FString& Val) { NewRow.DeactiveShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionBPPath"), RowName, [&](const FString& Val) { NewRow.CollisionBPPath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ChainEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ChainEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TargetChainEffectAliasWhenZeroShieldArray"), RowName, [&](const TArray<FString>& Val) { NewRow.TargetChainEffectAliasWhenZeroShieldArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("StanceAlias"), RowName, [&](const FString& Val) { NewRow.StanceAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveAttackedCollisionGroupArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveAttackedCollisionGroupArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState1"), RowName, [&](const FString& Val) { NewRow.ActorState1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState2"), RowName, [&](const FString& Val) { NewRow.ActorState2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState3"), RowName, [&](const FString& Val) { NewRow.ActorState3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState4"), RowName, [&](const FString& Val) { NewRow.ActorState4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState5"), RowName, [&](const FString& Val) { NewRow.ActorState5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState6"), RowName, [&](const FString& Val) { NewRow.ActorState6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState7"), RowName, [&](const FString& Val) { NewRow.ActorState7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState8"), RowName, [&](const FString& Val) { NewRow.ActorState8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState9"), RowName, [&](const FString& Val) { NewRow.ActorState9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState10"), RowName, [&](const FString& Val) { NewRow.ActorState10 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState1"), RowName, [&](float Val) { NewRow.DelayActorState1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState2"), RowName, [&](float Val) { NewRow.DelayActorState2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState3"), RowName, [&](float Val) { NewRow.DelayActorState3 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState4"), RowName, [&](float Val) { NewRow.DelayActorState4 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState5"), RowName, [&](float Val) { NewRow.DelayActorState5 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState6"), RowName, [&](float Val) { NewRow.DelayActorState6 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState7"), RowName, [&](float Val) { NewRow.DelayActorState7 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState8"), RowName, [&](float Val) { NewRow.DelayActorState8 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState9"), RowName, [&](float Val) { NewRow.DelayActorState9 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayActorState10"), RowName, [&](float Val) { NewRow.DelayActorState10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action1"), RowName, [&](const FString& Val) { NewRow.Action1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionValue1"), RowName, [&](const FString& Val) { NewRow.ActionValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action2"), RowName, [&](const FString& Val) { NewRow.Action2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionValue2"), RowName, [&](const FString& Val) { NewRow.ActionValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action3"), RowName, [&](const FString& Val) { NewRow.Action3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionValue3"), RowName, [&](const FString& Val) { NewRow.ActionValue3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action4"), RowName, [&](const FString& Val) { NewRow.Action4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionValue4"), RowName, [&](const FString& Val) { NewRow.ActionValue4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action5"), RowName, [&](const FString& Val) { NewRow.Action5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionValue5"), RowName, [&](const FString& Val) { NewRow.ActionValue5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackedCollisionGroup"), RowName, [&](const FString& Val) { NewRow.AttackedCollisionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackedCollisionGroupResultType"), RowName, [&](const FString& Val) { NewRow.AttackedCollisionGroupResultType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ImmuneEffectGroupArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ImmuneEffectGroupArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAlias"), RowName, [&](const FString& Val) { NewRow.MoveAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseGetupMoveAlias"), RowName, [&](bool Val) { NewRow.bUseGetupMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd1"), RowName, [&](const FString& Val) { NewRow.ConditionEnd1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd2"), RowName, [&](const FString& Val) { NewRow.ConditionEnd2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd3"), RowName, [&](const FString& Val) { NewRow.ConditionEnd3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd4"), RowName, [&](const FString& Val) { NewRow.ConditionEnd4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd5"), RowName, [&](const FString& Val) { NewRow.ConditionEnd5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveStanceAnimType"), RowName, [&](const FString& Val) { NewRow.ActiveStanceAnimType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableSave"), RowName, [&](bool Val) { NewRow.bEnableSave = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bPlayOnDead"), RowName, [&](bool Val) { NewRow.bPlayOnDead = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopOnRevival"), RowName, [&](bool Val) { NewRow.bStopOnRevival = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWarpToSafeLocationOnDead"), RowName, [&](bool Val) { NewRow.bWarpToSafeLocationOnDead = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpToSafeLocationEffectAlias"), RowName, [&](const FString& Val) { NewRow.WarpToSafeLocationEffectAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreTimeScale"), RowName, [&](bool Val) { NewRow.bIgnoreTimeScale = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAggroToConstructorActor"), RowName, [&](bool Val) { NewRow.bAggroToConstructorActor = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDeadType"), RowName, [&](const FString& Val) { NewRow.TargetDeadType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SoundDecibel"), RowName, [&](float Val) { NewRow.SoundDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SoundLife"), RowName, [&](float Val) { NewRow.SoundLife = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionChainType"), RowName, [&](const FString& Val) { NewRow.ConditionChainType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionChainSelfEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionChainSelfEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionChainTargetEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionChainTargetEffectAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseCreateEffectPosition"), RowName, [&](bool Val) { NewRow.bUseCreateEffectPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectStartPosition"), RowName, [&](const FString& Val) { NewRow.CreateEffectStartPosition = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCreateEffectPositionOnGround"), RowName, [&](bool Val) { NewRow.bCreateEffectPositionOnGround = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EffectPositionOnGroundCheckDistance"), RowName, [&](float Val) { NewRow.EffectPositionOnGroundCheckDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectRelativeLocation"), RowName, [&](const FString& Val) { NewRow.CreateEffectRelativeLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectLocationRandomRange"), RowName, [&](const FString& Val) { NewRow.CreateEffectLocationRandomRange = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectRelativeAxisType"), RowName, [&](const FString& Val) { NewRow.CreateEffectRelativeAxisType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectRelativeRotation"), RowName, [&](const FString& Val) { NewRow.CreateEffectRelativeRotation = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectRotationRandomRange"), RowName, [&](const FString& Val) { NewRow.CreateEffectRotationRandomRange = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bShowEffectTimeUI"), RowName, [&](bool Val) { NewRow.bShowEffectTimeUI = Val; });
        TryApplyStringField(RowDataObject, TEXT("Loc_EffectTimeUIText"), RowName, [&](const FString& Val) { NewRow.Loc_EffectTimeUIText = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectUIType"), RowName, [&](const FString& Val) { NewRow.EffectUIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias1"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType1"), RowName, [&](const FString& Val) { NewRow.ExpansionType1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue1"), RowName, [&](const FString& Val) { NewRow.ExpansionValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias2"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType2"), RowName, [&](const FString& Val) { NewRow.ExpansionType2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue2"), RowName, [&](const FString& Val) { NewRow.ExpansionValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias3"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType3"), RowName, [&](const FString& Val) { NewRow.ExpansionType3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue3"), RowName, [&](const FString& Val) { NewRow.ExpansionValue3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias4"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType4"), RowName, [&](const FString& Val) { NewRow.ExpansionType4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue4"), RowName, [&](const FString& Val) { NewRow.ExpansionValue4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias5"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType5"), RowName, [&](const FString& Val) { NewRow.ExpansionType5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue5"), RowName, [&](const FString& Val) { NewRow.ExpansionValue5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShowKeyTag"), RowName, [&](const FString& Val) { NewRow.ShowKeyTag = Val; });
        TryApplyBoolField(RowDataObject, TEXT("LoopElement"), RowName, [&](bool Val) { NewRow.LoopElement = Val; });
        TryApplyStringField(RowDataObject, TEXT("ElementTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.ElementTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ElementType"), RowName, [&](const FString& Val) { NewRow.ElementType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ElementAmount"), RowName, [&](float Val) { NewRow.ElementAmount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bProjectileAttackPossible"), RowName, [&](bool Val) { NewRow.bProjectileAttackPossible = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ProjectileAttackDamage"), RowName, [&](float Val) { NewRow.ProjectileAttackDamage = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveProjectileTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.ActiveProjectileTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveProjectileAlias"), RowName, [&](const FString& Val) { NewRow.ActiveProjectileAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bPauseWhenAttachLevelSequence"), RowName, [&](bool Val) { NewRow.bPauseWhenAttachLevelSequence = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bPauseWhenPlayerAttachLevelSequence"), RowName, [&](bool Val) { NewRow.bPauseWhenPlayerAttachLevelSequence = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionAssistTargetFilter"), RowName, [&](const FString& Val) { NewRow.ActionAssistTargetFilter = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActionAssistCheckDelay"), RowName, [&](float Val) { NewRow.ActionAssistCheckDelay = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActionAssistActiveTime"), RowName, [&](float Val) { NewRow.ActionAssistActiveTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

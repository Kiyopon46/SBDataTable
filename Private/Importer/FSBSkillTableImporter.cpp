#include "Importer/FSBSkillTableImporter.h"
#include "SBSkillTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSkillTableImporter"

FString FSBSkillTableImporter::GetDataTableName() const
{
    return "SkillTable";
}

TFunction<void()> FSBSkillTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSkillTableImporter::GetRowStruct() const
{
    return FSBSkillTableProperty::StaticStruct();
}

void FSBSkillTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSkillTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Loc_SkillName"), RowName, [&](const FString& Val) { NewRow.Loc_SkillName = Val; });
        TryApplyStringField(RowDataObject, TEXT("Loc_SystemNotice_IsBeingCooltime"), RowName, [&](const FString& Val) { NewRow.Loc_SystemNotice_IsBeingCooltime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Loc_SystemNotice_CannotUse"), RowName, [&](const FString& Val) { NewRow.Loc_SystemNotice_CannotUse = Val; });
        TryApplyStringField(RowDataObject, TEXT("Flag"), RowName, [&](const FString& Val) { NewRow.Flag = Val; });
        TryApplyStringField(RowDataObject, TEXT("AdditiveSkillDamageGroup"), RowName, [&](const FString& Val) { NewRow.AdditiveSkillDamageGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AchievementTags"), RowName, [&](const TArray<FString>& Val) { NewRow.AchievementTags = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartDelay"), RowName, [&](float Val) { NewRow.StartDelay = Val; });
        TryApplyIntField(RowDataObject, TEXT("StartDelayTick"), RowName, [&](int32 Val) { NewRow.StartDelayTick = Val; });
        TryApplyIntField(RowDataObject, TEXT("HitLevel"), RowName, [&](int32 Val) { NewRow.HitLevel = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttributeType"), RowName, [&](const FString& Val) { NewRow.AttributeType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillType"), RowName, [&](const FString& Val) { NewRow.SkillType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorAction"), RowName, [&](const FString& Val) { NewRow.ActorAction = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectSkillFlag"), RowName, [&](const FString& Val) { NewRow.EffectSkillFlag = Val; });
        TryApplyStringField(RowDataObject, TEXT("AISkillFlag"), RowName, [&](const FString& Val) { NewRow.AISkillFlag = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckTargetExists"), RowName, [&](bool Val) { NewRow.bCheckTargetExists = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckNoTargeting"), RowName, [&](bool Val) { NewRow.bCheckNoTargeting = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUsableSkillWhenTargetSwimming"), RowName, [&](bool Val) { NewRow.bUsableSkillWhenTargetSwimming = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckValidMoveAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckValidMoveAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckInvalidMoveAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckInvalidMoveAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckActiveStepValidMove"), RowName, [&](bool Val) { NewRow.bCheckActiveStepValidMove = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.TargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnOverrideTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.LockOnOverrideTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneEventActorTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.ZoneEventActorTargetFilterAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIAttackableDistance"), RowName, [&](float Val) { NewRow.AIAttackableDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchActiveStepByTargetFlag"), RowName, [&](bool Val) { NewRow.bBranchActiveStepByTargetFlag = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchActiveStepByPrevSkill"), RowName, [&](bool Val) { NewRow.bBranchActiveStepByPrevSkill = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchActiveStepByFoot"), RowName, [&](bool Val) { NewRow.bBranchActiveStepByFoot = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchActiveStepByActivatingSkill"), RowName, [&](bool Val) { NewRow.bBranchActiveStepByActivatingSkill = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchActiveStepByBulletItemAlias"), RowName, [&](bool Val) { NewRow.bBranchActiveStepByBulletItemAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("BranchActiveStepByUsedCount"), RowName, [&](int32 Val) { NewRow.BranchActiveStepByUsedCount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchActiveStepByCheckConsumeItem"), RowName, [&](bool Val) { NewRow.bBranchActiveStepByCheckConsumeItem = Val; });
        TryApplyIntField(RowDataObject, TEXT("BranchRandomStep"), RowName, [&](int32 Val) { NewRow.BranchRandomStep = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBranchLinkSkillRandomStep"), RowName, [&](bool Val) { NewRow.bBranchLinkSkillRandomStep = Val; });
        TryApplyStringField(RowDataObject, TEXT("FirstActiveStepByEffect"), RowName, [&](const FString& Val) { NewRow.FirstActiveStepByEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextSkillBranchStep"), RowName, [&](const FString& Val) { NewRow.NextSkillBranchStep = Val; });
        TryApplyStringField(RowDataObject, TEXT("FirstSkillActiveAlias"), RowName, [&](const FString& Val) { NewRow.FirstSkillActiveAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("JustActionTime"), RowName, [&](float Val) { NewRow.JustActionTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("JustActionTime_StoryMode"), RowName, [&](float Val) { NewRow.JustActionTime_StoryMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("JustSkillActiveAlias"), RowName, [&](const FString& Val) { NewRow.JustSkillActiveAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ConditionJustAction_MoveDirectionToTargetAngle"), RowName, [&](float Val) { NewRow.ConditionJustAction_MoveDirectionToTargetAngle = Val; });
        TryApplyStringField(RowDataObject, TEXT("UseableCheckGroup"), RowName, [&](const FString& Val) { NewRow.UseableCheckGroup = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CoolTime"), RowName, [&](float Val) { NewRow.CoolTime = Val; });
        TryApplyIntField(RowDataObject, TEXT("UsableCount"), RowName, [&](int32 Val) { NewRow.UsableCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("UseEnergyType"), RowName, [&](const FString& Val) { NewRow.UseEnergyType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UseEnergyAmount"), RowName, [&](float Val) { NewRow.UseEnergyAmount = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConsumeItemAlias"), RowName, [&](const FString& Val) { NewRow.ConsumeItemAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConsumeItemCountType"), RowName, [&](const FString& Val) { NewRow.ConsumeItemCountType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AttackDamageRate"), RowName, [&](float Val) { NewRow.AttackDamageRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldAttackDamageRate"), RowName, [&](float Val) { NewRow.ShieldAttackDamageRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FixedDamage"), RowName, [&](float Val) { NewRow.FixedDamage = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Cancelable"), RowName, [&](bool Val) { NewRow.Cancelable = Val; });
        TryApplyBoolField(RowDataObject, TEXT("ActiveSkillWhileCutoff"), RowName, [&](bool Val) { NewRow.ActiveSkillWhileCutoff = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDeadAnimBS"), RowName, [&](const FString& Val) { NewRow.TargetDeadAnimBS = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDeadType"), RowName, [&](const FString& Val) { NewRow.TargetDeadType = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldObjectHitShow"), RowName, [&](const FString& Val) { NewRow.WorldObjectHitShow = Val; });
        TryApplyBoolField(RowDataObject, TEXT("RotateInputDirection"), RowName, [&](bool Val) { NewRow.RotateInputDirection = Val; });
        TryApplyBoolField(RowDataObject, TEXT("RotateInputDirectionIgnoreLockOn"), RowName, [&](bool Val) { NewRow.RotateInputDirectionIgnoreLockOn = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSwitchBattleMode"), RowName, [&](bool Val) { NewRow.bSwitchBattleMode = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUnlockOn"), RowName, [&](bool Val) { NewRow.bUnlockOn = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreBlockSkill"), RowName, [&](bool Val) { NewRow.bIgnoreBlockSkill = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDelayAutoLockOn"), RowName, [&](bool Val) { NewRow.bDelayAutoLockOn = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableWorldCustomTimeScale"), RowName, [&](bool Val) { NewRow.bDisableWorldCustomTimeScale = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableSkillShowStepWhenStandalone"), RowName, [&](bool Val) { NewRow.bDisableSkillShowStepWhenStandalone = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableEventMove"), RowName, [&](bool Val) { NewRow.bDisableEventMove = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableStopWhenAttachedLevelSeq"), RowName, [&](bool Val) { NewRow.bDisableStopWhenAttachedLevelSeq = Val; });
        TryApplyStringField(RowDataObject, TEXT("AcquisitionSkillAlias"), RowName, [&](const FString& Val) { NewRow.AcquisitionSkillAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd_Swimming"), RowName, [&](const FString& Val) { NewRow.ConditionEnd_Swimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd_UWSwimming"), RowName, [&](const FString& Val) { NewRow.ConditionEnd_UWSwimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd_MeleeCombat"), RowName, [&](const FString& Val) { NewRow.ConditionEnd_MeleeCombat = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd_RangedCombat"), RowName, [&](const FString& Val) { NewRow.ConditionEnd_RangedCombat = Val; });
        TryApplyBoolField(RowDataObject, TEXT("ConditionEnd_bTargetDead"), RowName, [&](bool Val) { NewRow.ConditionEnd_bTargetDead = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreAttackSpeedStat"), RowName, [&](bool Val) { NewRow.bIgnoreAttackSpeedStat = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopCloaking"), RowName, [&](bool Val) { NewRow.bStopCloaking = Val; });
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
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias6"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType6"), RowName, [&](const FString& Val) { NewRow.ExpansionType6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue6"), RowName, [&](const FString& Val) { NewRow.ExpansionValue6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias7"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType7"), RowName, [&](const FString& Val) { NewRow.ExpansionType7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue7"), RowName, [&](const FString& Val) { NewRow.ExpansionValue7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias8"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType8"), RowName, [&](const FString& Val) { NewRow.ExpansionType8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue8"), RowName, [&](const FString& Val) { NewRow.ExpansionValue8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias9"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType9"), RowName, [&](const FString& Val) { NewRow.ExpansionType9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue9"), RowName, [&](const FString& Val) { NewRow.ExpansionValue9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionFromAcquisitionAlias10"), RowName, [&](const FString& Val) { NewRow.ExpansionFromAcquisitionAlias10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionType10"), RowName, [&](const FString& Val) { NewRow.ExpansionType10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExpansionValue10"), RowName, [&](const FString& Val) { NewRow.ExpansionValue10 = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bApplyOffScreenIndicator"), RowName, [&](bool Val) { NewRow.bApplyOffScreenIndicator = Val; });
        TryApplyStringField(RowDataObject, TEXT("AimLockOnTargetVibrationSetPath"), RowName, [&](const FString& Val) { NewRow.AimLockOnTargetVibrationSetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrainingRoomLogStringKey"), RowName, [&](const FString& Val) { NewRow.TrainingRoomLogStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

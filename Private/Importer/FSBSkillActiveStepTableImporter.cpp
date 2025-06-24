#include "Importer/FSBSkillActiveStepTableImporter.h"
#include "SBSkillActiveStepTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSkillActiveStepTableImporter"

FString FSBSkillActiveStepTableImporter::GetDataTableName() const
{
    return "SkillActiveStepTable";
}

TFunction<void()> FSBSkillActiveStepTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSkillActiveStepTableImporter::GetRowStruct() const
{
    return FSBSkillActiveStepTableProperty::StaticStruct();
}

void FSBSkillActiveStepTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSkillActiveStepTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Duration"), RowName, [&](float Val) { NewRow.Duration = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackDirection"), RowName, [&](const FString& Val) { NewRow.AttackDirection = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SkillAttackDamageRate"), RowName, [&](float Val) { NewRow.SkillAttackDamageRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SkillShieldAttackDamageRate"), RowName, [&](float Val) { NewRow.SkillShieldAttackDamageRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SkillFixedDamageRate"), RowName, [&](float Val) { NewRow.SkillFixedDamageRate = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableParry"), RowName, [&](bool Val) { NewRow.AvailableParry = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableSuperParry"), RowName, [&](bool Val) { NewRow.AvailableSuperParry = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableGuard"), RowName, [&](bool Val) { NewRow.AvailableGuard = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustParry"), RowName, [&](bool Val) { NewRow.AvailableJustParry = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustAction"), RowName, [&](bool Val) { NewRow.AvailableJustAction = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustGuard"), RowName, [&](bool Val) { NewRow.AvailableJustGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAlias"), RowName, [&](const FString& Val) { NewRow.NextStepAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenParry"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenJustParry"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenJustParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenPerfectParry"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenPerfectParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenSuperParry"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenSuperParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenGuard"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenBreakGuard"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenBreakGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenCancel"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenCancel = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenHit"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenHit = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenPerfectHit"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenPerfectHit = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenHoldRelease"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenHoldRelease = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenHoldAndDualSenseTriggerEffectWeaponFired"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenHoldAndDualSenseTriggerEffectWeaponFired = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenAttacked"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenAttacked = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenNoTarget"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenNoTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenLinkBreak"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenLinkBreak = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepAliasWhenInvalidItemConsume"), RowName, [&](const FString& Val) { NewRow.NextStepAliasWhenInvalidItemConsume = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextStepCheckEffectArray"), RowName, [&](const FString& Val) { NewRow.NextStepCheckEffectArray = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ResultInterval"), RowName, [&](float Val) { NewRow.ResultInterval = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAlias"), RowName, [&](const FString& Val) { NewRow.SkillResultAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenJustParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenJustParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenPerfectParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenPerfectParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenSuperParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenSuperParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenGuard"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenBreakGuard"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenBreakGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultElementType"), RowName, [&](const FString& Val) { NewRow.SkillResultElementType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SkillResultElementAmount"), RowName, [&](float Val) { NewRow.SkillResultElementAmount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreAttackSpeedStat"), RowName, [&](bool Val) { NewRow.bIgnoreAttackSpeedStat = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreNoDamageState"), RowName, [&](bool Val) { NewRow.bIgnoreNoDamageState = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartSelfEffect"), RowName, [&](const FString& Val) { NewRow.StartSelfEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTargetEffect"), RowName, [&](const FString& Val) { NewRow.StartTargetEffect = Val; });
        TryApplyBoolField(RowDataObject, TEXT("StopSelfMove"), RowName, [&](bool Val) { NewRow.StopSelfMove = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("SelfMoveAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.SelfMoveAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TargetMoveAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.TargetMoveAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulShowPath"), RowName, [&](const FString& Val) { NewRow.PeacefulShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShowPath"), RowName, [&](const FString& Val) { NewRow.ShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bShowWithCasterDrone"), RowName, [&](bool Val) { NewRow.bShowWithCasterDrone = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetShowPath"), RowName, [&](const FString& Val) { NewRow.TargetShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("UsableNonTargetProjectileTargetType"), RowName, [&](const FString& Val) { NewRow.UsableNonTargetProjectileTargetType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UsableNonTargetProjectileAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UsableNonTargetProjectileAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("UsableTargetProjectileTargetType"), RowName, [&](const FString& Val) { NewRow.UsableTargetProjectileTargetType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UsableTargetProjectileAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UsableTargetProjectileAliasArray = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UsableProjectileConsecutiveDelay"), RowName, [&](float Val) { NewRow.UsableProjectileConsecutiveDelay = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEveryFrameHitCheck"), RowName, [&](bool Val) { NewRow.bEveryFrameHitCheck = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitDetectionType"), RowName, [&](const FString& Val) { NewRow.HitDetectionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDetectionType"), RowName, [&](const FString& Val) { NewRow.TargetDetectionType = Val; });
        TryApplyIntField(RowDataObject, TEXT("AimLockOnTargetMaxCount"), RowName, [&](int32 Val) { NewRow.AimLockOnTargetMaxCount = Val; });
        TryApplyIntField(RowDataObject, TEXT("AimLockOnTargetOverlapCount"), RowName, [&](int32 Val) { NewRow.AimLockOnTargetOverlapCount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bRetargeting"), RowName, [&](bool Val) { NewRow.bRetargeting = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.OverrideTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackCollisionGroupArray"), RowName, [&](const FString& Val) { NewRow.AttackCollisionGroupArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackedCollisionGroupArray"), RowName, [&](const FString& Val) { NewRow.AttackedCollisionGroupArray = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BlockingCollisionDelayTime"), RowName, [&](float Val) { NewRow.BlockingCollisionDelayTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("BlockingCollisionArray"), RowName, [&](const TArray<FString>& Val) { NewRow.BlockingCollisionArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableRuleMoveBlockArea"), RowName, [&](bool Val) { NewRow.bDisableRuleMoveBlockArea = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLookAtTarget"), RowName, [&](bool Val) { NewRow.bLookAtTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtTargetRotationTime"), RowName, [&](float Val) { NewRow.LookAtTargetRotationTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtTargetLeftMaxAngle"), RowName, [&](float Val) { NewRow.LookAtTargetLeftMaxAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtTargetRightMaxAngle"), RowName, [&](float Val) { NewRow.LookAtTargetRightMaxAngle = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectSelfPosition"), RowName, [&](const FString& Val) { NewRow.CreateEffectSelfPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreateEffectTargetPosition"), RowName, [&](const FString& Val) { NewRow.CreateEffectTargetPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDeadEffect"), RowName, [&](const FString& Val) { NewRow.TargetDeadEffect = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCritical"), RowName, [&](bool Val) { NewRow.bCritical = Val; });
        TryApplyBoolField(RowDataObject, TEXT("PostStep"), RowName, [&](bool Val) { NewRow.PostStep = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PostStepDelay"), RowName, [&](float Val) { NewRow.PostStepDelay = Val; });
        TryApplyBoolField(RowDataObject, TEXT("CanCutoff"), RowName, [&](bool Val) { NewRow.CanCutoff = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenMoving"), RowName, [&](bool Val) { NewRow.bStopWhenMoving = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableLockOnRotation"), RowName, [&](bool Val) { NewRow.bDisableLockOnRotation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSkipWhenZeroVelocity"), RowName, [&](bool Val) { NewRow.bSkipWhenZeroVelocity = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd1"), RowName, [&](const FString& Val) { NewRow.ConditionEnd1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd2"), RowName, [&](const FString& Val) { NewRow.ConditionEnd2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SoundDecibel"), RowName, [&](float Val) { NewRow.SoundDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SoundLife"), RowName, [&](float Val) { NewRow.SoundLife = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IgnoreNextComboTime"), RowName, [&](bool Val) { NewRow.IgnoreNextComboTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepResulted"), RowName, [&](bool Val) { NewRow.bKeepResulted = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreHitStop"), RowName, [&](bool Val) { NewRow.bIgnoreHitStop = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ZoneEventDestructionDelayMinTime"), RowName, [&](float Val) { NewRow.ZoneEventDestructionDelayMinTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ZoneEventDestructionDelayMaxTime"), RowName, [&](float Val) { NewRow.ZoneEventDestructionDelayMaxTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIActionRequestGroup"), RowName, [&](const FString& Val) { NewRow.UIActionRequestGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIChargingVisibleType"), RowName, [&](const FString& Val) { NewRow.UIChargingVisibleType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StepUIEvent"), RowName, [&](const FString& Val) { NewRow.StepUIEvent = Val; });
        TryApplyIntField(RowDataObject, TEXT("TPS_AimChargingCount"), RowName, [&](int32 Val) { NewRow.TPS_AimChargingCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("DualSenseTriggerEffect"), RowName, [&](const FString& Val) { NewRow.DualSenseTriggerEffect = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DualSenseTriggerEffectParameters"), RowName, [&](const TArray<FString>& Val) { NewRow.DualSenseTriggerEffectParameters = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bReleaseCommandKeyWhenStop"), RowName, [&](bool Val) { NewRow.bReleaseCommandKeyWhenStop = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bResetComboTime"), RowName, [&](bool Val) { NewRow.bResetComboTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckValidMoveAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckValidMoveAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("Loc_SystemNotice"), RowName, [&](const FString& Val) { NewRow.Loc_SystemNotice = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrainingRoomOverrideAcquisitionSkillAlias"), RowName, [&](const FString& Val) { NewRow.TrainingRoomOverrideAcquisitionSkillAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrainingRoomLogStringKey"), RowName, [&](const FString& Val) { NewRow.TrainingRoomLogStringKey = Val; });
        TryApplyBoolField(RowDataObject, TEXT("TrainingRoomForceLearned"), RowName, [&](bool Val) { NewRow.TrainingRoomForceLearned = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionAssistTargetFilter"), RowName, [&](const FString& Val) { NewRow.ActionAssistTargetFilter = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActionAssistCheckDelay"), RowName, [&](float Val) { NewRow.ActionAssistCheckDelay = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActionAssistActiveTime"), RowName, [&](float Val) { NewRow.ActionAssistActiveTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActionAssistCollisionPreCheckTime"), RowName, [&](float Val) { NewRow.ActionAssistCollisionPreCheckTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSkillActiveStepTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSkillActiveStepTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Duration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttackDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SkillAttackDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SkillShieldAttackDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SkillFixedDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableSuperParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenJustParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenPerfectParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenSuperParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenBreakGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenCancel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenPerfectHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenHoldRelease;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenHoldAndDualSenseTriggerEffectWeaponFired;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenAttacked;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenNoTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenLinkBreak;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepAliasWhenInvalidItemConsume;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextStepCheckEffectArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ResultInterval;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenJustParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenPerfectParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenSuperParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenBreakGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultElementType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SkillResultElementAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreAttackSpeedStat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreNoDamageState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartSelfEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTargetEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StopSelfMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> SelfMoveAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TargetMoveAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowWithCasterDrone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UsableNonTargetProjectileTargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> UsableNonTargetProjectileAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UsableTargetProjectileTargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> UsableTargetProjectileAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UsableProjectileConsecutiveDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEveryFrameHitCheck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitDetectionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDetectionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AimLockOnTargetMaxCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AimLockOnTargetOverlapCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRetargeting;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OverrideTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttackCollisionGroupArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttackedCollisionGroupArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BlockingCollisionDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> BlockingCollisionArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableRuleMoveBlockArea;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLookAtTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtTargetRotationTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtTargetLeftMaxAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtTargetRightMaxAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectSelfPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectTargetPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDeadEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCritical;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool PostStep;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PostStepDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool CanCutoff;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableLockOnRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSkipWhenZeroVelocity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoundDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoundLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IgnoreNextComboTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepResulted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreHitStop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ZoneEventDestructionDelayMinTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ZoneEventDestructionDelayMaxTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIActionRequestGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIChargingVisibleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StepUIEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TPS_AimChargingCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DualSenseTriggerEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DualSenseTriggerEffectParameters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bReleaseCommandKeyWhenStop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bResetComboTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckValidMoveAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Loc_SystemNotice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrainingRoomOverrideAcquisitionSkillAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrainingRoomLogStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool TrainingRoomForceLearned;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionAssistTargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActionAssistCheckDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActionAssistActiveTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActionAssistCollisionPreCheckTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
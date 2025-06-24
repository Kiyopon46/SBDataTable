#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSkillTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSkillTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Loc_SkillName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Loc_SystemNotice_IsBeingCooltime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Loc_SystemNotice_CannotUse;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Flag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AdditiveSkillDamageGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AchievementTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StartDelayTick;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 HitLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttributeType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectSkillFlag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AISkillFlag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckTargetExists;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckNoTargeting;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUsableSkillWhenTargetSwimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckValidMoveAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckInvalidMoveAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckActiveStepValidMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnOverrideTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneEventActorTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIAttackableDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchActiveStepByTargetFlag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchActiveStepByPrevSkill;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchActiveStepByFoot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchActiveStepByActivatingSkill;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchActiveStepByBulletItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BranchActiveStepByUsedCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchActiveStepByCheckConsumeItem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BranchRandomStep;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBranchLinkSkillRandomStep;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FirstActiveStepByEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextSkillBranchStep;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FirstSkillActiveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float JustActionTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float JustActionTime_StoryMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JustSkillActiveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ConditionJustAction_MoveDirectionToTargetAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UseableCheckGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CoolTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 UsableCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UseEnergyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UseEnergyAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConsumeItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConsumeItemCountType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AttackDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShieldAttackDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FixedDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Cancelable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ActiveSkillWhileCutoff;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDeadAnimBS;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDeadType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldObjectHitShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RotateInputDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RotateInputDirectionIgnoreLockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSwitchBattleMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUnlockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreBlockSkill;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDelayAutoLockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableWorldCustomTimeScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableSkillShowStepWhenStandalone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableEventMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableStopWhenAttachedLevelSeq;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AcquisitionSkillAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd_Swimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd_UWSwimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd_MeleeCombat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd_RangedCombat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ConditionEnd_bTargetDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreAttackSpeedStat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopCloaking;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bApplyOffScreenIndicator;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AimLockOnTargetVibrationSetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrainingRoomLogStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
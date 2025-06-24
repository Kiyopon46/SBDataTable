#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSkillCommandTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSkillCommandTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandActionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillPriorityAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombinationKey1CheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombinationKey2CheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombinationCrossUpCheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombinationCrossDownCheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombinationCrossLeftCheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombinationCrossRightCheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Command;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PressCheckCommand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitResult;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HitResultTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float JustActiveTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WeaponType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bJumping;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bWallRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bSprint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bLockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bFly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bSwimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bUWSwimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bFirstSwimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bEventMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bInBreakfallRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bTachyGaugeMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckActiveEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckActiveNoneEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BulletItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> NextComboCommandArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckTargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPressInputTypeWhenNoOtherCommand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool GlobalCommand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckSameSkillActivation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckInputDirectionWhenHold;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckInputDirectionAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bInputDirectionByActorLocalAxis;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinInputDirectionAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxInputDirectionAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HoldDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AICommandActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandUIImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReqEnergyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReqEnergyAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableReservation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBlockJumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreLastUsedHoldSkill;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRemainToggleSprint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DualSenseCheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DualSenseTriggerEffectStateConditions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bForceRootTrainingRoomLog;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bForceComboTrainingRoomLog;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DiableLockOnTargetFrameCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterStanceTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterStanceTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CombatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bGroupAttacker;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDetectCloakingTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BoneBlendType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Condition_DestroyCollisionGroupArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_ActorStat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_ActorStatCheck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Condition_ActorStatCheckValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_DeactiveActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_DeactiveActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_DeactiveActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_DeactiveActorState4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_DeactiveActorState5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_BattleMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_Jumping;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_Swimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_EventMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_ChildGuideAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Condition_ActiveEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Condition_NoneEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_PressCommandKey1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bActiveCheck_PressCommandKey1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_PressCommandKey2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bActiveCheck_PressCommandKey2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_WeaponEquipmentAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_SecondaryWeaponEquipmentAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_ThirdlyWeaponEquipmentAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_FourthlyWeaponEquipmentAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_MetaAI_TiredState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bInfiniteStance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CommandArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWallHitPossible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bImpossibleLockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bImpossibleAutoLockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDropAttackTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBackStabTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bForceFoldingWeapon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableGravity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RunSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LockOnRunSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LockOnWalkSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float JoggingRunSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotateAnglePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideCustomMovementMaxSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSoundDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSoundLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WalkSoundPeriod;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RunSoundDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RunSoundLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RunSoundPeriod;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SprintSoundDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SprintSoundLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SprintSoundPeriod;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float JumpSoundDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float JumpSoundLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartShowPathWhenPeaceful;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartShowPathWhenBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndShowPathWhenPeaceful;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndShowPathWhenBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Peaceful_UpperBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Peaceful_LowerBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Battle_UpperBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Battle_LowerBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Groggy_UpperBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Groggy_LowerBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Down_UpperBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Down_LowerBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Dead_UpperBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Dead_LowerBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Airborne_UpperBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimSet_Airborne_LowerBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableMovingTransit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableIdleAdditiveAnimWhenPeaceful;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableIdleAdditiveAnimWhenBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OverridePhysicsAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DeadSkillAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DeadSkillPercentage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DeadSkillSelfDeadType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DeadSkillRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> MountableEquipmentAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bOptimizeWithSignificanceManager;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bClearCommandInputWhenEnd;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
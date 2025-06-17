// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterTableProperty.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterTableProperty : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Rank;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Tribe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString OverrideTribe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> ConditionList_OverrideTribe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> LinkSkillRandomActiveStepFlagArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Flag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MaxHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MaxShield;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MaxStamina;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float PhysicAttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RangeAttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ShieldAttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float StaminaAttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ShieldBlock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float BaseDamageReductionByShield;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DamageReductionPerShieldBock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ShieldRegenPerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ShieldRegenPerSecondWhenBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float StaminaRegenPerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float HPRegenPerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 BetaGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MaxBetaGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 BurstGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MaxBurstGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MaxTachyGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 UnlockBurstGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 UnlockTachyGauge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 UnlockTPSMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 GainTachyGaugeOnDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AttackSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CriticalPercentage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CriticalValueRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ShieldIgnorePercentage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float SmallWeightTypeDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float LargeWeightTypeDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RangeAttackDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float MeleeAttackDamageReductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RangeAttackDamageReductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DownStateDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float GroggyStateDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AirborneStateDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float FireAttributeDamageReductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float IceAttributeDamageReductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float LightningAttributeDamageReductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float PoisonAttributeDamageReductionRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AdditiveFixedDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float LowHpDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float HighHpDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DOTDamageAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float FinalHPDamageReduceRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float FinalShieldDamageReduceRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float BetaGaugeAdditiveRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float Luck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DrainHpByAttackPowerRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DrainHpFixedValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float SprintableStaminaValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasWhenZeroHPArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasWhenZeroShieldArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasWhenZeroStaminaArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasByRageSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasBy1ComboSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasBy2ComboSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasBy3ComboSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasBy4ComboSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasBy5ComboSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasByCriticalHitArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasToTargetByCriticalHitArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString WeightType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float MeshScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float TargetFilterRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ProjectileTargetFilterRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RuleMoveBlockAreaRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RuleMoveBlockAreaZHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RuleMoveBlockAreaOffsetX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RuleMoveBlockAreaOffsetY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RuleMoveBlockAreaOffsetZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float RuleMoveBlockCheckRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> DefaultEffectArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasByPlayerCount2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasByPlayerCount3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasByPlayerCount4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasArrayForStoryMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString DifficultyStatGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> DefaultEquipmentAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString AttackerEffectWhenDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString DeadAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DespawnTimeAfterDeath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString DespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString SpawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> SpawnEffectList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString MonsterWarpShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> MonsterWarpEffectList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString CollisionGroupName1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CollisionGroupGauge1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasArrayWhenCollisionGroupGaugeZero1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString CollisionGroupName2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CollisionGroupGauge2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasArrayWhenCollisionGroupGaugeZero2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString CollisionGroupName3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CollisionGroupGauge3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasArrayWhenCollisionGroupGaugeZero3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString CollisionGroupName4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CollisionGroupGauge4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasArrayWhenCollisionGroupGaugeZero4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString CollisionGroupName5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float CollisionGroupGauge5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> EffectAliasArrayWhenCollisionGroupGaugeZero5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> StanceAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString DefaultStanceAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float GetupTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString GetupMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float GroggyEndTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> JumpEffectArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FString> SprintEffectArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float VelocityWhenWallHitBounce;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float VelocityDelayWhenWallHitBounce;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString BehaviorTreeRes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString DefaultDetectAIAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString NarrowDetectAIAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString DetectViewingSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AIAuditorySenseRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AIAuditorySenseDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AIAuditorySenseDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString ActorType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString RefAppearance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 HitDefenseLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float BackSideHitAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float InteractionRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float InteractionAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Interaction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float InteractionUpperHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float InteractionLowerHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString RewardSpawnBucketType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString RewardOverrideSaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString RewardFormationAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bDisableCollisionWhenDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float DisableCollisionDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString UITextWhenDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackRecoveryPotion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackBullet1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackBullet2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackBullet3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackBullet4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackBullet5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackBullet6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 StackConsumable7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 GearSlotCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 ExoSpineSlotCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float FishingAttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bEncroachmentable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString EncroachmentType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bExcludingRuleMoveIgnoreTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString RelativeShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float LockOnCameraBoomHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float LockOnCameraBoomLeftRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float LockOnCameraBoomLength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bKeepData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bUseDistancePooling;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bUseDelayBattleStanceTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bApplyDamageWhenPlayerAlive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString ScanDisplayType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString OverrideEquip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bSequenceCharacter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString OverrideCharacterSoundSet;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString FileSuffix;
};

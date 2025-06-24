#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBProjectileTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBProjectileTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResourcePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bGroupProjectile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LifeType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LifeTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestroyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DestroyWaitTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhysicsType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AttackDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShieldAttackDamageRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float HitRepeatInterval;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProjectileShotEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProjectileArriveEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProjectileEndEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProjectileLifeTimeEndEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ElementType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ElementAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CreateProjectileAliasArrayWhenDestruction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProjectileEndCreateProjectileAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableProjectileEndCreateProjectileWhenDestruction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableProjectileEndCreateProjectileWhenHitGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneEventActorTriggerTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileSuperParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileJustParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileJustGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillResultAliasWhenProjectileReflectHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDeadType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLockOnHitTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndLocationDecalShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableSuperParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustGuard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DecalPlayExceptTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bImpossibleReflect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReflectYawRandMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReflectYawRandMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReflectPitchRandMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReflectPitchRandMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReflectDestTargetOverrideAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReflectTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReflectJustActionTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReflectProjectileArriveEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableUIEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreNoDamageState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bProjectileAttackPossible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ProjectileAttackDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDestructible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Life;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProjectileDestructionAttackerEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProjectileDestructionOwnerEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ZoneEventDestructionDelayMinTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ZoneEventDestructionDelayMaxTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckShotPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckShotPositionSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShotTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovementType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTargetUpdate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTargetTransformType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTargetTransformName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStartTargetTransformRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTargetRelativeLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartTargetRelativeRotationPitch;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartTargetRelativeRotationYaw;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartTargetRelativeRotationRoll;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartTargetRelativeAxisType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDestTargetUpdateWhenSpawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetUpdate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetTransformType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetTransformName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetRandomRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetRelativeLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetRelativeLocationCurvePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetRelativeLocationScaleCurvePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestTargetRelativeAxisType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDestTargetLocationToGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FixedLocationTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FixedLocationRemainingDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FixedLocationAdditiveForwardDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartToDestDirectionDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Speed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpeedRandom;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Accelation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSpeedFromDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MovementCurveRepeatDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MovementCurveScaleDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovementCurveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovementCurve;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAutoGenerationMovementCurve;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AutoGenerationMovementCurveMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AutoGenerationMovementCurveMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AutoGenerationMovementCurveRecordTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Gravity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpeedFromMinDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpeedFromMaxDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParabolicMotionXYSpeedPerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAdditiveLocationByTargetVelocity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AdditiveDestTargetForwardDistanceWhenVelocityMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationMinDistancePowerWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationMaxDistancePowerWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationMinDistanceWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationMaxDistanceWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomVelocityMinWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomVelocityMaxWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomYawMinWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomYawMaxWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomPitchMinWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RandomPitchMaxWhenGuidedMissile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MissOffsetRandomRangeMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MissOffsetRandomRangeMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBeamTracking;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeamTrackingStartTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeamTrackingBlendInTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeamTrackingEndTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeamTrackingBlendOutTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeamTrackingTargetDistacne;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBeamTrackingTargetFollow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeamFixedDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ChainAttackCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PoolCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSignalUI;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
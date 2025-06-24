#include "Importer/FSBProjectileTableImporter.h"
#include "SBProjectileTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBProjectileTableImporter"

FString FSBProjectileTableImporter::GetDataTableName() const
{
    return "ProjectileTable";
}

TFunction<void()> FSBProjectileTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBProjectileTableImporter::GetRowStruct() const
{
    return FSBProjectileTableProperty::StaticStruct();
}

void FSBProjectileTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBProjectileTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResourcePath"), RowName, [&](const FString& Val) { NewRow.ResourcePath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bGroupProjectile"), RowName, [&](bool Val) { NewRow.bGroupProjectile = Val; });
        TryApplyStringField(RowDataObject, TEXT("LifeType"), RowName, [&](const FString& Val) { NewRow.LifeType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LifeTime"), RowName, [&](float Val) { NewRow.LifeTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestroyType"), RowName, [&](const FString& Val) { NewRow.DestroyType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DestroyWaitTime"), RowName, [&](float Val) { NewRow.DestroyWaitTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhysicsType"), RowName, [&](const FString& Val) { NewRow.PhysicsType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AttackDamageRate"), RowName, [&](float Val) { NewRow.AttackDamageRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldAttackDamageRate"), RowName, [&](float Val) { NewRow.ShieldAttackDamageRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitType"), RowName, [&](const FString& Val) { NewRow.HitType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("HitRepeatInterval"), RowName, [&](float Val) { NewRow.HitRepeatInterval = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.TargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProjectileShotEffectAlias"), RowName, [&](const FString& Val) { NewRow.ProjectileShotEffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProjectileArriveEffectAlias"), RowName, [&](const FString& Val) { NewRow.ProjectileArriveEffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProjectileEndEffectAlias"), RowName, [&](const FString& Val) { NewRow.ProjectileEndEffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProjectileLifeTimeEndEffectAlias"), RowName, [&](const FString& Val) { NewRow.ProjectileLifeTimeEndEffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ElementType"), RowName, [&](const FString& Val) { NewRow.ElementType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ElementAmount"), RowName, [&](float Val) { NewRow.ElementAmount = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CreateProjectileAliasArrayWhenDestruction"), RowName, [&](const TArray<FString>& Val) { NewRow.CreateProjectileAliasArrayWhenDestruction = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProjectileEndCreateProjectileAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ProjectileEndCreateProjectileAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableProjectileEndCreateProjectileWhenDestruction"), RowName, [&](bool Val) { NewRow.bDisableProjectileEndCreateProjectileWhenDestruction = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableProjectileEndCreateProjectileWhenHitGround"), RowName, [&](bool Val) { NewRow.bDisableProjectileEndCreateProjectileWhenHitGround = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneEventActorTriggerTag"), RowName, [&](const FString& Val) { NewRow.ZoneEventActorTriggerTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileHit"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileHit = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileSuperParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileSuperParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileGuard"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileJustParry"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileJustParry = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileJustGuard"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileJustGuard = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillResultAliasWhenProjectileReflectHit"), RowName, [&](const FString& Val) { NewRow.SkillResultAliasWhenProjectileReflectHit = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDeadType"), RowName, [&](const FString& Val) { NewRow.TargetDeadType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLockOnHitTarget"), RowName, [&](bool Val) { NewRow.bLockOnHitTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndLocationDecalShowPath"), RowName, [&](const FString& Val) { NewRow.EndLocationDecalShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableParry"), RowName, [&](bool Val) { NewRow.AvailableParry = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableSuperParry"), RowName, [&](bool Val) { NewRow.AvailableSuperParry = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableGuard"), RowName, [&](bool Val) { NewRow.AvailableGuard = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustParry"), RowName, [&](bool Val) { NewRow.AvailableJustParry = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustGuard"), RowName, [&](bool Val) { NewRow.AvailableJustGuard = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AvailableJustAction"), RowName, [&](bool Val) { NewRow.AvailableJustAction = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DecalPlayExceptTime"), RowName, [&](float Val) { NewRow.DecalPlayExceptTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bImpossibleReflect"), RowName, [&](bool Val) { NewRow.bImpossibleReflect = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ReflectYawRandMin"), RowName, [&](float Val) { NewRow.ReflectYawRandMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ReflectYawRandMax"), RowName, [&](float Val) { NewRow.ReflectYawRandMax = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ReflectPitchRandMin"), RowName, [&](float Val) { NewRow.ReflectPitchRandMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ReflectPitchRandMax"), RowName, [&](float Val) { NewRow.ReflectPitchRandMax = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReflectDestTargetOverrideAlias"), RowName, [&](const FString& Val) { NewRow.ReflectDestTargetOverrideAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReflectTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.ReflectTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReflectJustActionTargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.ReflectJustActionTargetFilterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReflectProjectileArriveEffectAlias"), RowName, [&](const FString& Val) { NewRow.ReflectProjectileArriveEffectAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableUIEvent"), RowName, [&](bool Val) { NewRow.bDisableUIEvent = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreNoDamageState"), RowName, [&](bool Val) { NewRow.bIgnoreNoDamageState = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bProjectileAttackPossible"), RowName, [&](bool Val) { NewRow.bProjectileAttackPossible = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ProjectileAttackDamage"), RowName, [&](float Val) { NewRow.ProjectileAttackDamage = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreCollision"), RowName, [&](bool Val) { NewRow.bIgnoreCollision = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDestructible"), RowName, [&](bool Val) { NewRow.bDestructible = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Life"), RowName, [&](float Val) { NewRow.Life = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProjectileDestructionAttackerEffectAlias"), RowName, [&](const FString& Val) { NewRow.ProjectileDestructionAttackerEffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProjectileDestructionOwnerEffectAlias"), RowName, [&](const FString& Val) { NewRow.ProjectileDestructionOwnerEffectAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ZoneEventDestructionDelayMinTime"), RowName, [&](float Val) { NewRow.ZoneEventDestructionDelayMinTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ZoneEventDestructionDelayMaxTime"), RowName, [&](float Val) { NewRow.ZoneEventDestructionDelayMaxTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckShotPosition"), RowName, [&](bool Val) { NewRow.bCheckShotPosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckShotPositionSocketName"), RowName, [&](const FString& Val) { NewRow.CheckShotPositionSocketName = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartDelayTime"), RowName, [&](float Val) { NewRow.StartDelayTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShotTime"), RowName, [&](float Val) { NewRow.ShotTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovementType"), RowName, [&](const FString& Val) { NewRow.MovementType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTarget"), RowName, [&](const FString& Val) { NewRow.StartTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTargetUpdate"), RowName, [&](const FString& Val) { NewRow.StartTargetUpdate = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTargetTransformType"), RowName, [&](const FString& Val) { NewRow.StartTargetTransformType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTargetTransformName"), RowName, [&](const FString& Val) { NewRow.StartTargetTransformName = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStartTargetTransformRotation"), RowName, [&](bool Val) { NewRow.bStartTargetTransformRotation = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTargetRelativeLocation"), RowName, [&](const FString& Val) { NewRow.StartTargetRelativeLocation = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartTargetRelativeRotationPitch"), RowName, [&](float Val) { NewRow.StartTargetRelativeRotationPitch = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartTargetRelativeRotationYaw"), RowName, [&](float Val) { NewRow.StartTargetRelativeRotationYaw = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartTargetRelativeRotationRoll"), RowName, [&](float Val) { NewRow.StartTargetRelativeRotationRoll = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartTargetRelativeAxisType"), RowName, [&](const FString& Val) { NewRow.StartTargetRelativeAxisType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTarget"), RowName, [&](const FString& Val) { NewRow.DestTarget = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDestTargetUpdateWhenSpawn"), RowName, [&](bool Val) { NewRow.bDestTargetUpdateWhenSpawn = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetUpdate"), RowName, [&](const FString& Val) { NewRow.DestTargetUpdate = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetTransformType"), RowName, [&](const FString& Val) { NewRow.DestTargetTransformType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetTransformName"), RowName, [&](const FString& Val) { NewRow.DestTargetTransformName = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetRandomRange"), RowName, [&](const FString& Val) { NewRow.DestTargetRandomRange = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetRelativeLocation"), RowName, [&](const FString& Val) { NewRow.DestTargetRelativeLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetRelativeLocationCurvePath"), RowName, [&](const FString& Val) { NewRow.DestTargetRelativeLocationCurvePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetRelativeLocationScaleCurvePath"), RowName, [&](const FString& Val) { NewRow.DestTargetRelativeLocationScaleCurvePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestTargetRelativeAxisType"), RowName, [&](const FString& Val) { NewRow.DestTargetRelativeAxisType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDestTargetLocationToGround"), RowName, [&](bool Val) { NewRow.bDestTargetLocationToGround = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FixedLocationTime"), RowName, [&](float Val) { NewRow.FixedLocationTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FixedLocationRemainingDistance"), RowName, [&](float Val) { NewRow.FixedLocationRemainingDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FixedLocationAdditiveForwardDistance"), RowName, [&](float Val) { NewRow.FixedLocationAdditiveForwardDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartToDestDirectionDistance"), RowName, [&](float Val) { NewRow.StartToDestDirectionDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Speed"), RowName, [&](float Val) { NewRow.Speed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SpeedRandom"), RowName, [&](float Val) { NewRow.SpeedRandom = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Accelation"), RowName, [&](float Val) { NewRow.Accelation = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinSpeed"), RowName, [&](float Val) { NewRow.MinSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxSpeed"), RowName, [&](float Val) { NewRow.MaxSpeed = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSpeedFromDuration"), RowName, [&](bool Val) { NewRow.bSpeedFromDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MovementCurveRepeatDistance"), RowName, [&](float Val) { NewRow.MovementCurveRepeatDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MovementCurveScaleDistance"), RowName, [&](float Val) { NewRow.MovementCurveScaleDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovementCurveType"), RowName, [&](const FString& Val) { NewRow.MovementCurveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovementCurve"), RowName, [&](const FString& Val) { NewRow.MovementCurve = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAutoGenerationMovementCurve"), RowName, [&](bool Val) { NewRow.bAutoGenerationMovementCurve = Val; });
        TryApplyStringField(RowDataObject, TEXT("AutoGenerationMovementCurveMin"), RowName, [&](const FString& Val) { NewRow.AutoGenerationMovementCurveMin = Val; });
        TryApplyStringField(RowDataObject, TEXT("AutoGenerationMovementCurveMax"), RowName, [&](const FString& Val) { NewRow.AutoGenerationMovementCurveMax = Val; });
        TryApplyStringField(RowDataObject, TEXT("AutoGenerationMovementCurveRecordTime"), RowName, [&](const FString& Val) { NewRow.AutoGenerationMovementCurveRecordTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Gravity"), RowName, [&](float Val) { NewRow.Gravity = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SpeedFromMinDistance"), RowName, [&](float Val) { NewRow.SpeedFromMinDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SpeedFromMaxDistance"), RowName, [&](float Val) { NewRow.SpeedFromMaxDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ParabolicMotionXYSpeedPerSecond"), RowName, [&](float Val) { NewRow.ParabolicMotionXYSpeedPerSecond = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAdditiveLocationByTargetVelocity"), RowName, [&](bool Val) { NewRow.bAdditiveLocationByTargetVelocity = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AdditiveDestTargetForwardDistanceWhenVelocityMove"), RowName, [&](float Val) { NewRow.AdditiveDestTargetForwardDistanceWhenVelocityMove = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationMinDistancePowerWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RotationMinDistancePowerWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationMaxDistancePowerWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RotationMaxDistancePowerWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationMinDistanceWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RotationMinDistanceWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationMaxDistanceWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RotationMaxDistanceWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RandomVelocityMinWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RandomVelocityMinWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RandomVelocityMaxWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RandomVelocityMaxWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RandomYawMinWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RandomYawMinWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RandomYawMaxWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RandomYawMaxWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RandomPitchMinWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RandomPitchMinWhenGuidedMissile = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RandomPitchMaxWhenGuidedMissile"), RowName, [&](float Val) { NewRow.RandomPitchMaxWhenGuidedMissile = Val; });
        TryApplyStringField(RowDataObject, TEXT("MissOffsetRandomRangeMin"), RowName, [&](const FString& Val) { NewRow.MissOffsetRandomRangeMin = Val; });
        TryApplyStringField(RowDataObject, TEXT("MissOffsetRandomRangeMax"), RowName, [&](const FString& Val) { NewRow.MissOffsetRandomRangeMax = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBeamTracking"), RowName, [&](bool Val) { NewRow.bBeamTracking = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeamTrackingStartTime"), RowName, [&](float Val) { NewRow.BeamTrackingStartTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeamTrackingBlendInTime"), RowName, [&](float Val) { NewRow.BeamTrackingBlendInTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeamTrackingEndTime"), RowName, [&](float Val) { NewRow.BeamTrackingEndTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeamTrackingBlendOutTime"), RowName, [&](float Val) { NewRow.BeamTrackingBlendOutTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeamTrackingTargetDistacne"), RowName, [&](float Val) { NewRow.BeamTrackingTargetDistacne = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBeamTrackingTargetFollow"), RowName, [&](bool Val) { NewRow.bBeamTrackingTargetFollow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeamFixedDistance"), RowName, [&](float Val) { NewRow.BeamFixedDistance = Val; });
        TryApplyIntField(RowDataObject, TEXT("ChainAttackCount"), RowName, [&](int32 Val) { NewRow.ChainAttackCount = Val; });
        TryApplyIntField(RowDataObject, TEXT("PoolCount"), RowName, [&](int32 Val) { NewRow.PoolCount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSignalUI"), RowName, [&](bool Val) { NewRow.bSignalUI = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

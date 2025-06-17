#include "Importer/FSBCharacterTableImporter.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

void FSBCharacterTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject)
{
    for (const auto& RowPair : RowsObject->Values) {
        FString RowName = RowPair.Key;

        const TSharedPtr<FJsonObject>* RowDataObjectPtr;
        if (!RowPair.Value->TryGetObject(RowDataObjectPtr) || !RowDataObjectPtr) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid row object for RowName: %s"), *RowName);
            continue;
        }

        const TSharedPtr<FJsonObject>& RowDataObject = *RowDataObjectPtr;

        FSBCharacterTableProperty NewRow;
        this->TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("Rank"), RowName, [&](const FString& Val) { NewRow.Rank = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("Tribe"), RowName, [&](const FString& Val) { NewRow.Tribe = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("OverrideTribe"), RowName, [&](const FString& Val) { NewRow.OverrideTribe = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("ConditionList_OverrideTribe"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionList_OverrideTribe = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("Tags"), RowName, [&](const TArray<FString>& Val) { NewRow.Tags = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("LinkSkillRandomActiveStepFlagArray"), RowName, [&](const TArray<FString>& Val) { NewRow.LinkSkillRandomActiveStepFlagArray = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("Flag"), RowName, [&](const FString& Val) { NewRow.Flag = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MaxHP"), RowName, [&](int32 Val) { NewRow.MaxHP = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MaxShield"), RowName, [&](int32 Val) { NewRow.MaxShield = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MaxStamina"), RowName, [&](int32 Val) { NewRow.MaxStamina = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("PhysicAttackPower"), RowName, [&](float Val) { NewRow.PhysicAttackPower = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RangeAttackPower"), RowName, [&](float Val) { NewRow.RangeAttackPower = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("ShieldAttackPower"), RowName, [&](float Val) { NewRow.ShieldAttackPower = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("StaminaAttackPower"), RowName, [&](float Val) { NewRow.StaminaAttackPower = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("ShieldBlock"), RowName, [&](float Val) { NewRow.ShieldBlock = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("BaseDamageReductionByShield"), RowName, [&](float Val) { NewRow.BaseDamageReductionByShield = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DamageReductionPerShieldBock"), RowName, [&](float Val) { NewRow.DamageReductionPerShieldBock = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("ShieldRegenPerSecond"), RowName, [&](float Val) { NewRow.ShieldRegenPerSecond = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("ShieldRegenPerSecondWhenBattle"), RowName, [&](float Val) { NewRow.ShieldRegenPerSecondWhenBattle = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("StaminaRegenPerSecond"), RowName, [&](float Val) { NewRow.StaminaRegenPerSecond = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("HPRegenPerSecond"), RowName, [&](float Val) { NewRow.HPRegenPerSecond = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("BetaGauge"), RowName, [&](int32 Val) { NewRow.BetaGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MaxBetaGauge"), RowName, [&](int32 Val) { NewRow.MaxBetaGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("BurstGauge"), RowName, [&](int32 Val) { NewRow.BurstGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MaxBurstGauge"), RowName, [&](int32 Val) { NewRow.MaxBurstGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MaxTachyGauge"), RowName, [&](int32 Val) { NewRow.MaxTachyGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("UnlockBurstGauge"), RowName, [&](int32 Val) { NewRow.UnlockBurstGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("UnlockTachyGauge"), RowName, [&](int32 Val) { NewRow.UnlockTachyGauge = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("UnlockTPSMode"), RowName, [&](int32 Val) { NewRow.UnlockTPSMode = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("GainTachyGaugeOnDead"), RowName, [&](int32 Val) { NewRow.GainTachyGaugeOnDead = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("MoveSpeed"), RowName, [&](int32 Val) { NewRow.MoveSpeed = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("AttackSpeed"), RowName, [&](float Val) { NewRow.AttackSpeed = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CriticalPercentage"), RowName, [&](float Val) { NewRow.CriticalPercentage = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CriticalValueRate"), RowName, [&](float Val) { NewRow.CriticalValueRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("ShieldIgnorePercentage"), RowName, [&](float Val) { NewRow.ShieldIgnorePercentage = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("SmallWeightTypeDamageAdditiveRate"), RowName, [&](float Val) { NewRow.SmallWeightTypeDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("LargeWeightTypeDamageAdditiveRate"), RowName, [&](float Val) { NewRow.LargeWeightTypeDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RangeAttackDamageAdditiveRate"), RowName, [&](float Val) { NewRow.RangeAttackDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("MeleeAttackDamageReductionRate"), RowName, [&](float Val) { NewRow.MeleeAttackDamageReductionRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RangeAttackDamageReductionRate"), RowName, [&](float Val) { NewRow.RangeAttackDamageReductionRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DownStateDamageAdditiveRate"), RowName, [&](float Val) { NewRow.DownStateDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("GroggyStateDamageAdditiveRate"), RowName, [&](float Val) { NewRow.GroggyStateDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("AirborneStateDamageAdditiveRate"), RowName, [&](float Val) { NewRow.AirborneStateDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("FireAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.FireAttributeDamageReductionRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("IceAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.IceAttributeDamageReductionRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("LightningAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.LightningAttributeDamageReductionRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("PoisonAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.PoisonAttributeDamageReductionRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("AdditiveFixedDamage"), RowName, [&](float Val) { NewRow.AdditiveFixedDamage = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("LowHpDamageAdditiveRate"), RowName, [&](float Val) { NewRow.LowHpDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("HighHpDamageAdditiveRate"), RowName, [&](float Val) { NewRow.HighHpDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DOTDamageAdditiveRate"), RowName, [&](float Val) { NewRow.DOTDamageAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("FinalHPDamageReduceRate"), RowName, [&](float Val) { NewRow.FinalHPDamageReduceRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("FinalShieldDamageReduceRate"), RowName, [&](float Val) { NewRow.FinalShieldDamageReduceRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("BetaGaugeAdditiveRate"), RowName, [&](float Val) { NewRow.BetaGaugeAdditiveRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("Luck"), RowName, [&](float Val) { NewRow.Luck = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DrainHpByAttackPowerRate"), RowName, [&](float Val) { NewRow.DrainHpByAttackPowerRate = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DrainHpFixedValue"), RowName, [&](float Val) { NewRow.DrainHpFixedValue = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("SprintableStaminaValue"), RowName, [&](float Val) { NewRow.SprintableStaminaValue = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasWhenZeroHPArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasWhenZeroHPArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasWhenZeroShieldArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasWhenZeroShieldArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasWhenZeroStaminaArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasWhenZeroStaminaArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByRageSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByRageSkillArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy1ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy1ComboSkillArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy2ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy2ComboSkillArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy3ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy3ComboSkillArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy4ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy4ComboSkillArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy5ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy5ComboSkillArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByCriticalHitArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByCriticalHitArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasToTargetByCriticalHitArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasToTargetByCriticalHitArray = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("WeightType"), RowName, [&](const FString& Val) { NewRow.WeightType = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("MeshScale"), RowName, [&](float Val) { NewRow.MeshScale = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("TargetFilterRadius"), RowName, [&](float Val) { NewRow.TargetFilterRadius = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("ProjectileTargetFilterRadius"), RowName, [&](float Val) { NewRow.ProjectileTargetFilterRadius = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaRadius"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaRadius = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaZHeight"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaZHeight = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaOffsetX"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaOffsetX = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaOffsetY"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaOffsetY = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaOffsetZ"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaOffsetZ = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockCheckRadius"), RowName, [&](float Val) { NewRow.RuleMoveBlockCheckRadius = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("DefaultEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DefaultEffectArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByPlayerCount2"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByPlayerCount2 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByPlayerCount3"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByPlayerCount3 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByPlayerCount4"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByPlayerCount4 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayForStoryMode"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayForStoryMode = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("DifficultyStatGroupAlias"), RowName, [&](const FString& Val) { NewRow.DifficultyStatGroupAlias = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("DefaultEquipmentAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DefaultEquipmentAliasArray = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("AttackerEffectWhenDead"), RowName, [&](const FString& Val) { NewRow.AttackerEffectWhenDead = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("DeadAlias"), RowName, [&](const FString& Val) { NewRow.DeadAlias = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DespawnTimeAfterDeath"), RowName, [&](float Val) { NewRow.DespawnTimeAfterDeath = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("DespawnShow"), RowName, [&](const FString& Val) { NewRow.DespawnShow = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("SpawnShow"), RowName, [&](const FString& Val) { NewRow.SpawnShow = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("SpawnEffectList"), RowName, [&](const TArray<FString>& Val) { NewRow.SpawnEffectList = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("MonsterWarpShow"), RowName, [&](const FString& Val) { NewRow.MonsterWarpShow = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("MonsterWarpEffectList"), RowName, [&](const TArray<FString>& Val) { NewRow.MonsterWarpEffectList = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("CollisionGroupName1"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName1 = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge1"), RowName, [&](float Val) { NewRow.CollisionGroupGauge1 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero1"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero1 = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("CollisionGroupName2"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName2 = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge2"), RowName, [&](float Val) { NewRow.CollisionGroupGauge2 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero2"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero2 = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("CollisionGroupName3"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName3 = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge3"), RowName, [&](float Val) { NewRow.CollisionGroupGauge3 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero3"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero3 = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("CollisionGroupName4"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName4 = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge4"), RowName, [&](float Val) { NewRow.CollisionGroupGauge4 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero4"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero4 = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("CollisionGroupName5"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName5 = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge5"), RowName, [&](float Val) { NewRow.CollisionGroupGauge5 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero5"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero5 = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("StanceAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.StanceAliasArray = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("DefaultStanceAlias"), RowName, [&](const FString& Val) { NewRow.DefaultStanceAlias = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("GetupTime"), RowName, [&](float Val) { NewRow.GetupTime = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("GetupMoveAlias"), RowName, [&](const FString& Val) { NewRow.GetupMoveAlias = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("GroggyEndTime"), RowName, [&](float Val) { NewRow.GroggyEndTime = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("JumpEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.JumpEffectArray = Val; });
        this->TryApplyStringArrayField(RowDataObject, TEXT("SprintEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.SprintEffectArray = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("VelocityWhenWallHitBounce"), RowName, [&](float Val) { NewRow.VelocityWhenWallHitBounce = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("VelocityDelayWhenWallHitBounce"), RowName, [&](float Val) { NewRow.VelocityDelayWhenWallHitBounce = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("BehaviorTreeRes"), RowName, [&](const FString& Val) { NewRow.BehaviorTreeRes = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("DefaultDetectAIAlias"), RowName, [&](const FString& Val) { NewRow.DefaultDetectAIAlias = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("NarrowDetectAIAlias"), RowName, [&](const FString& Val) { NewRow.NarrowDetectAIAlias = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("DetectViewingSocketName"), RowName, [&](const FString& Val) { NewRow.DetectViewingSocketName = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("AIAuditorySenseRadius"), RowName, [&](float Val) { NewRow.AIAuditorySenseRadius = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("AIAuditorySenseDecibel"), RowName, [&](float Val) { NewRow.AIAuditorySenseDecibel = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("AIAuditorySenseDuration"), RowName, [&](float Val) { NewRow.AIAuditorySenseDuration = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("ActorType"), RowName, [&](const FString& Val) { NewRow.ActorType = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("RefAppearance"), RowName, [&](const FString& Val) { NewRow.RefAppearance = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("HitDefenseLevel"), RowName, [&](int32 Val) { NewRow.HitDefenseLevel = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("BackSideHitAngle"), RowName, [&](float Val) { NewRow.BackSideHitAngle = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("InteractionRange"), RowName, [&](float Val) { NewRow.InteractionRange = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("InteractionAngle"), RowName, [&](float Val) { NewRow.InteractionAngle = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("Interaction"), RowName, [&](const FString& Val) { NewRow.Interaction = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("InteractionUpperHeight"), RowName, [&](float Val) { NewRow.InteractionUpperHeight = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("InteractionLowerHeight"), RowName, [&](float Val) { NewRow.InteractionLowerHeight = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.RewardGroupAlias = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("RewardSpawnBucketType"), RowName, [&](const FString& Val) { NewRow.RewardSpawnBucketType = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("RewardOverrideSaveType"), RowName, [&](const FString& Val) { NewRow.RewardOverrideSaveType = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("RewardFormationAssetPath"), RowName, [&](const FString& Val) { NewRow.RewardFormationAssetPath = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bDisableCollisionWhenDead"), RowName, [&](bool Val) { NewRow.bDisableCollisionWhenDead = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("DisableCollisionDelayTime"), RowName, [&](float Val) { NewRow.DisableCollisionDelayTime = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("UITextWhenDead"), RowName, [&](const FString& Val) { NewRow.UITextWhenDead = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackRecoveryPotion"), RowName, [&](int32 Val) { NewRow.StackRecoveryPotion = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackBullet1"), RowName, [&](int32 Val) { NewRow.StackBullet1 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackBullet2"), RowName, [&](int32 Val) { NewRow.StackBullet2 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackBullet3"), RowName, [&](int32 Val) { NewRow.StackBullet3 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackBullet4"), RowName, [&](int32 Val) { NewRow.StackBullet4 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackBullet5"), RowName, [&](int32 Val) { NewRow.StackBullet5 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackBullet6"), RowName, [&](int32 Val) { NewRow.StackBullet6 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable1"), RowName, [&](int32 Val) { NewRow.StackConsumable1 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable2"), RowName, [&](int32 Val) { NewRow.StackConsumable2 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable3"), RowName, [&](int32 Val) { NewRow.StackConsumable3 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable4"), RowName, [&](int32 Val) { NewRow.StackConsumable4 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable5"), RowName, [&](int32 Val) { NewRow.StackConsumable5 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable6"), RowName, [&](int32 Val) { NewRow.StackConsumable6 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("StackConsumable7"), RowName, [&](int32 Val) { NewRow.StackConsumable7 = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("GearSlotCount"), RowName, [&](int32 Val) { NewRow.GearSlotCount = Val; });
        this->TryApplyIntField(RowDataObject, TEXT("ExoSpineSlotCount"), RowName, [&](int32 Val) { NewRow.ExoSpineSlotCount = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("FishingAttackPower"), RowName, [&](float Val) { NewRow.FishingAttackPower = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bEncroachmentable"), RowName, [&](bool Val) { NewRow.bEncroachmentable = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("EncroachmentType"), RowName, [&](const FString& Val) { NewRow.EncroachmentType = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bExcludingRuleMoveIgnoreTarget"), RowName, [&](bool Val) { NewRow.bExcludingRuleMoveIgnoreTarget = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("RelativeShowPath"), RowName, [&](const FString& Val) { NewRow.RelativeShowPath = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("LockOnCameraBoomHeight"), RowName, [&](float Val) { NewRow.LockOnCameraBoomHeight = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("LockOnCameraBoomLeftRight"), RowName, [&](float Val) { NewRow.LockOnCameraBoomLeftRight = Val; });
        this->TryApplyFloatField(RowDataObject, TEXT("LockOnCameraBoomLength"), RowName, [&](float Val) { NewRow.LockOnCameraBoomLength = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bKeepData"), RowName, [&](bool Val) { NewRow.bKeepData = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bUseDistancePooling"), RowName, [&](bool Val) { NewRow.bUseDistancePooling = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bUseDelayBattleStanceTime"), RowName, [&](bool Val) { NewRow.bUseDelayBattleStanceTime = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bApplyDamageWhenPlayerAlive"), RowName, [&](bool Val) { NewRow.bApplyDamageWhenPlayerAlive = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("ScanDisplayType"), RowName, [&](const FString& Val) { NewRow.ScanDisplayType = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("Name"), RowName, [&](const FString& Val) { NewRow.Name = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("OverrideEquip"), RowName, [&](const FString& Val) { NewRow.OverrideEquip = Val; });
        this->TryApplyBoolField(RowDataObject, TEXT("bSequenceCharacter"), RowName, [&](bool Val) { NewRow.bSequenceCharacter = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("OverrideCharacterSoundSet"), RowName, [&](const FString& Val) { NewRow.OverrideCharacterSoundSet = Val; });
        this->TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // DataTable に追加（事前に UDataTable* TargetTable を作成している前提）
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

FString FSBCharacterTableImporter::GetPackagePath() const
{
    return TEXT("/Game/Local/Data/CharacterTable");
}

UScriptStruct* FSBCharacterTableImporter::GetRowStruct() const
{
    return FSBCharacterTableProperty::StaticStruct();
}

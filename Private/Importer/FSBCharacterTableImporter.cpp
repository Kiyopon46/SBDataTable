#include "Importer/FSBCharacterTableImporter.h"
#include "SBCharacterTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterTableImporter"

FSBMenuEntry FSBCharacterTableImporter::GetMenuEntry()
{
    FSBMenuEntry Entry;
    Entry.Name = "CharacterTableEntry";
    Entry.Label = LOCTEXT("CharacterTableEntry", "CharacterTable");
    Entry.Tooltip = LOCTEXT("CharacterTableEntry_Tooltip", "Run CharacterTable tool");

    Entry.Callback = [this]()
    {
        this->Execute();
    };

    return Entry;
}

FString FSBCharacterTableImporter::GetPackagePath() const
{
    return TEXT("/Game/Local/Data/CharacterTable");
}

UScriptStruct* FSBCharacterTableImporter::GetRowStruct() const
{
    return FSBCharacterTableProperty::StaticStruct();
}

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
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Rank"), RowName, [&](const FString& Val) { NewRow.Rank = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyStringField(RowDataObject, TEXT("Tribe"), RowName, [&](const FString& Val) { NewRow.Tribe = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideTribe"), RowName, [&](const FString& Val) { NewRow.OverrideTribe = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ConditionList_OverrideTribe"), RowName, [&](const TArray<FString>& Val) { NewRow.ConditionList_OverrideTribe = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Tags"), RowName, [&](const TArray<FString>& Val) { NewRow.Tags = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LinkSkillRandomActiveStepFlagArray"), RowName, [&](const TArray<FString>& Val) { NewRow.LinkSkillRandomActiveStepFlagArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("Flag"), RowName, [&](const FString& Val) { NewRow.Flag = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxHP"), RowName, [&](int32 Val) { NewRow.MaxHP = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxShield"), RowName, [&](int32 Val) { NewRow.MaxShield = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxStamina"), RowName, [&](int32 Val) { NewRow.MaxStamina = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PhysicAttackPower"), RowName, [&](float Val) { NewRow.PhysicAttackPower = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RangeAttackPower"), RowName, [&](float Val) { NewRow.RangeAttackPower = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldAttackPower"), RowName, [&](float Val) { NewRow.ShieldAttackPower = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StaminaAttackPower"), RowName, [&](float Val) { NewRow.StaminaAttackPower = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldBlock"), RowName, [&](float Val) { NewRow.ShieldBlock = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BaseDamageReductionByShield"), RowName, [&](float Val) { NewRow.BaseDamageReductionByShield = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DamageReductionPerShieldBock"), RowName, [&](float Val) { NewRow.DamageReductionPerShieldBock = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldRegenPerSecond"), RowName, [&](float Val) { NewRow.ShieldRegenPerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldRegenPerSecondWhenBattle"), RowName, [&](float Val) { NewRow.ShieldRegenPerSecondWhenBattle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StaminaRegenPerSecond"), RowName, [&](float Val) { NewRow.StaminaRegenPerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("HPRegenPerSecond"), RowName, [&](float Val) { NewRow.HPRegenPerSecond = Val; });
        TryApplyIntField(RowDataObject, TEXT("BetaGauge"), RowName, [&](int32 Val) { NewRow.BetaGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxBetaGauge"), RowName, [&](int32 Val) { NewRow.MaxBetaGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("BurstGauge"), RowName, [&](int32 Val) { NewRow.BurstGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxBurstGauge"), RowName, [&](int32 Val) { NewRow.MaxBurstGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxTachyGauge"), RowName, [&](int32 Val) { NewRow.MaxTachyGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("UnlockBurstGauge"), RowName, [&](int32 Val) { NewRow.UnlockBurstGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("UnlockTachyGauge"), RowName, [&](int32 Val) { NewRow.UnlockTachyGauge = Val; });
        TryApplyIntField(RowDataObject, TEXT("UnlockTPSMode"), RowName, [&](int32 Val) { NewRow.UnlockTPSMode = Val; });
        TryApplyIntField(RowDataObject, TEXT("GainTachyGaugeOnDead"), RowName, [&](int32 Val) { NewRow.GainTachyGaugeOnDead = Val; });
        TryApplyIntField(RowDataObject, TEXT("MoveSpeed"), RowName, [&](int32 Val) { NewRow.MoveSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AttackSpeed"), RowName, [&](float Val) { NewRow.AttackSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CriticalPercentage"), RowName, [&](float Val) { NewRow.CriticalPercentage = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CriticalValueRate"), RowName, [&](float Val) { NewRow.CriticalValueRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShieldIgnorePercentage"), RowName, [&](float Val) { NewRow.ShieldIgnorePercentage = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SmallWeightTypeDamageAdditiveRate"), RowName, [&](float Val) { NewRow.SmallWeightTypeDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LargeWeightTypeDamageAdditiveRate"), RowName, [&](float Val) { NewRow.LargeWeightTypeDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RangeAttackDamageAdditiveRate"), RowName, [&](float Val) { NewRow.RangeAttackDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MeleeAttackDamageReductionRate"), RowName, [&](float Val) { NewRow.MeleeAttackDamageReductionRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RangeAttackDamageReductionRate"), RowName, [&](float Val) { NewRow.RangeAttackDamageReductionRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DownStateDamageAdditiveRate"), RowName, [&](float Val) { NewRow.DownStateDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("GroggyStateDamageAdditiveRate"), RowName, [&](float Val) { NewRow.GroggyStateDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AirborneStateDamageAdditiveRate"), RowName, [&](float Val) { NewRow.AirborneStateDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FireAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.FireAttributeDamageReductionRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("IceAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.IceAttributeDamageReductionRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LightningAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.LightningAttributeDamageReductionRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PoisonAttributeDamageReductionRate"), RowName, [&](float Val) { NewRow.PoisonAttributeDamageReductionRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AdditiveFixedDamage"), RowName, [&](float Val) { NewRow.AdditiveFixedDamage = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LowHpDamageAdditiveRate"), RowName, [&](float Val) { NewRow.LowHpDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("HighHpDamageAdditiveRate"), RowName, [&](float Val) { NewRow.HighHpDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DOTDamageAdditiveRate"), RowName, [&](float Val) { NewRow.DOTDamageAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FinalHPDamageReduceRate"), RowName, [&](float Val) { NewRow.FinalHPDamageReduceRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FinalShieldDamageReduceRate"), RowName, [&](float Val) { NewRow.FinalShieldDamageReduceRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BetaGaugeAdditiveRate"), RowName, [&](float Val) { NewRow.BetaGaugeAdditiveRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Luck"), RowName, [&](float Val) { NewRow.Luck = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DrainHpByAttackPowerRate"), RowName, [&](float Val) { NewRow.DrainHpByAttackPowerRate = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DrainHpFixedValue"), RowName, [&](float Val) { NewRow.DrainHpFixedValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SprintableStaminaValue"), RowName, [&](float Val) { NewRow.SprintableStaminaValue = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasWhenZeroHPArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasWhenZeroHPArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasWhenZeroShieldArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasWhenZeroShieldArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasWhenZeroStaminaArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasWhenZeroStaminaArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByRageSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByRageSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy1ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy1ComboSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy2ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy2ComboSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy3ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy3ComboSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy4ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy4ComboSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasBy5ComboSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasBy5ComboSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByCriticalHitArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByCriticalHitArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasToTargetByCriticalHitArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasToTargetByCriticalHitArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("WeightType"), RowName, [&](const FString& Val) { NewRow.WeightType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MeshScale"), RowName, [&](float Val) { NewRow.MeshScale = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetFilterRadius"), RowName, [&](float Val) { NewRow.TargetFilterRadius = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ProjectileTargetFilterRadius"), RowName, [&](float Val) { NewRow.ProjectileTargetFilterRadius = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaRadius"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaRadius = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaZHeight"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaZHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaOffsetX"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaOffsetX = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaOffsetY"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaOffsetY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockAreaOffsetZ"), RowName, [&](float Val) { NewRow.RuleMoveBlockAreaOffsetZ = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RuleMoveBlockCheckRadius"), RowName, [&](float Val) { NewRow.RuleMoveBlockCheckRadius = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DefaultEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DefaultEffectArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByPlayerCount2"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByPlayerCount2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByPlayerCount3"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByPlayerCount3 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasByPlayerCount4"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasByPlayerCount4 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayForStoryMode"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayForStoryMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("DifficultyStatGroupAlias"), RowName, [&](const FString& Val) { NewRow.DifficultyStatGroupAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DefaultEquipmentAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DefaultEquipmentAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackerEffectWhenDead"), RowName, [&](const FString& Val) { NewRow.AttackerEffectWhenDead = Val; });
        TryApplyStringField(RowDataObject, TEXT("DeadAlias"), RowName, [&](const FString& Val) { NewRow.DeadAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DespawnTimeAfterDeath"), RowName, [&](float Val) { NewRow.DespawnTimeAfterDeath = Val; });
        TryApplyStringField(RowDataObject, TEXT("DespawnShow"), RowName, [&](const FString& Val) { NewRow.DespawnShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnShow"), RowName, [&](const FString& Val) { NewRow.SpawnShow = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("SpawnEffectList"), RowName, [&](const TArray<FString>& Val) { NewRow.SpawnEffectList = Val; });
        TryApplyStringField(RowDataObject, TEXT("MonsterWarpShow"), RowName, [&](const FString& Val) { NewRow.MonsterWarpShow = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("MonsterWarpEffectList"), RowName, [&](const TArray<FString>& Val) { NewRow.MonsterWarpEffectList = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionGroupName1"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge1"), RowName, [&](float Val) { NewRow.CollisionGroupGauge1 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero1"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionGroupName2"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge2"), RowName, [&](float Val) { NewRow.CollisionGroupGauge2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero2"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionGroupName3"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName3 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge3"), RowName, [&](float Val) { NewRow.CollisionGroupGauge3 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero3"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionGroupName4"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName4 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge4"), RowName, [&](float Val) { NewRow.CollisionGroupGauge4 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero4"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionGroupName5"), RowName, [&](const FString& Val) { NewRow.CollisionGroupName5 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CollisionGroupGauge5"), RowName, [&](float Val) { NewRow.CollisionGroupGauge5 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArrayWhenCollisionGroupGaugeZero5"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArrayWhenCollisionGroupGaugeZero5 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StanceAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.StanceAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("DefaultStanceAlias"), RowName, [&](const FString& Val) { NewRow.DefaultStanceAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("GetupTime"), RowName, [&](float Val) { NewRow.GetupTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("GetupMoveAlias"), RowName, [&](const FString& Val) { NewRow.GetupMoveAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("GroggyEndTime"), RowName, [&](float Val) { NewRow.GroggyEndTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("JumpEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.JumpEffectArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("SprintEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.SprintEffectArray = Val; });
        TryApplyFloatField(RowDataObject, TEXT("VelocityWhenWallHitBounce"), RowName, [&](float Val) { NewRow.VelocityWhenWallHitBounce = Val; });
        TryApplyFloatField(RowDataObject, TEXT("VelocityDelayWhenWallHitBounce"), RowName, [&](float Val) { NewRow.VelocityDelayWhenWallHitBounce = Val; });
        TryApplyStringField(RowDataObject, TEXT("BehaviorTreeRes"), RowName, [&](const FString& Val) { NewRow.BehaviorTreeRes = Val; });
        TryApplyStringField(RowDataObject, TEXT("DefaultDetectAIAlias"), RowName, [&](const FString& Val) { NewRow.DefaultDetectAIAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("NarrowDetectAIAlias"), RowName, [&](const FString& Val) { NewRow.NarrowDetectAIAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("DetectViewingSocketName"), RowName, [&](const FString& Val) { NewRow.DetectViewingSocketName = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIAuditorySenseRadius"), RowName, [&](float Val) { NewRow.AIAuditorySenseRadius = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIAuditorySenseDecibel"), RowName, [&](float Val) { NewRow.AIAuditorySenseDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIAuditorySenseDuration"), RowName, [&](float Val) { NewRow.AIAuditorySenseDuration = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorType"), RowName, [&](const FString& Val) { NewRow.ActorType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RefAppearance"), RowName, [&](const FString& Val) { NewRow.RefAppearance = Val; });
        TryApplyIntField(RowDataObject, TEXT("HitDefenseLevel"), RowName, [&](int32 Val) { NewRow.HitDefenseLevel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BackSideHitAngle"), RowName, [&](float Val) { NewRow.BackSideHitAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionRange"), RowName, [&](float Val) { NewRow.InteractionRange = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionAngle"), RowName, [&](float Val) { NewRow.InteractionAngle = Val; });
        TryApplyStringField(RowDataObject, TEXT("Interaction"), RowName, [&](const FString& Val) { NewRow.Interaction = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionUpperHeight"), RowName, [&](float Val) { NewRow.InteractionUpperHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionLowerHeight"), RowName, [&](float Val) { NewRow.InteractionLowerHeight = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnBucketType"), RowName, [&](const FString& Val) { NewRow.RewardSpawnBucketType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardOverrideSaveType"), RowName, [&](const FString& Val) { NewRow.RewardOverrideSaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardFormationAssetPath"), RowName, [&](const FString& Val) { NewRow.RewardFormationAssetPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableCollisionWhenDead"), RowName, [&](bool Val) { NewRow.bDisableCollisionWhenDead = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DisableCollisionDelayTime"), RowName, [&](float Val) { NewRow.DisableCollisionDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("UITextWhenDead"), RowName, [&](const FString& Val) { NewRow.UITextWhenDead = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackRecoveryPotion"), RowName, [&](int32 Val) { NewRow.StackRecoveryPotion = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackBullet1"), RowName, [&](int32 Val) { NewRow.StackBullet1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackBullet2"), RowName, [&](int32 Val) { NewRow.StackBullet2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackBullet3"), RowName, [&](int32 Val) { NewRow.StackBullet3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackBullet4"), RowName, [&](int32 Val) { NewRow.StackBullet4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackBullet5"), RowName, [&](int32 Val) { NewRow.StackBullet5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackBullet6"), RowName, [&](int32 Val) { NewRow.StackBullet6 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable1"), RowName, [&](int32 Val) { NewRow.StackConsumable1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable2"), RowName, [&](int32 Val) { NewRow.StackConsumable2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable3"), RowName, [&](int32 Val) { NewRow.StackConsumable3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable4"), RowName, [&](int32 Val) { NewRow.StackConsumable4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable5"), RowName, [&](int32 Val) { NewRow.StackConsumable5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable6"), RowName, [&](int32 Val) { NewRow.StackConsumable6 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackConsumable7"), RowName, [&](int32 Val) { NewRow.StackConsumable7 = Val; });
        TryApplyIntField(RowDataObject, TEXT("GearSlotCount"), RowName, [&](int32 Val) { NewRow.GearSlotCount = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExoSpineSlotCount"), RowName, [&](int32 Val) { NewRow.ExoSpineSlotCount = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FishingAttackPower"), RowName, [&](float Val) { NewRow.FishingAttackPower = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEncroachmentable"), RowName, [&](bool Val) { NewRow.bEncroachmentable = Val; });
        TryApplyStringField(RowDataObject, TEXT("EncroachmentType"), RowName, [&](const FString& Val) { NewRow.EncroachmentType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bExcludingRuleMoveIgnoreTarget"), RowName, [&](bool Val) { NewRow.bExcludingRuleMoveIgnoreTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("RelativeShowPath"), RowName, [&](const FString& Val) { NewRow.RelativeShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LockOnCameraBoomHeight"), RowName, [&](float Val) { NewRow.LockOnCameraBoomHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LockOnCameraBoomLeftRight"), RowName, [&](float Val) { NewRow.LockOnCameraBoomLeftRight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LockOnCameraBoomLength"), RowName, [&](float Val) { NewRow.LockOnCameraBoomLength = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepData"), RowName, [&](bool Val) { NewRow.bKeepData = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseDistancePooling"), RowName, [&](bool Val) { NewRow.bUseDistancePooling = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseDelayBattleStanceTime"), RowName, [&](bool Val) { NewRow.bUseDelayBattleStanceTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bApplyDamageWhenPlayerAlive"), RowName, [&](bool Val) { NewRow.bApplyDamageWhenPlayerAlive = Val; });
        TryApplyStringField(RowDataObject, TEXT("ScanDisplayType"), RowName, [&](const FString& Val) { NewRow.ScanDisplayType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Name"), RowName, [&](const FString& Val) { NewRow.Name = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideEquip"), RowName, [&](const FString& Val) { NewRow.OverrideEquip = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSequenceCharacter"), RowName, [&](bool Val) { NewRow.bSequenceCharacter = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideCharacterSoundSet"), RowName, [&](const FString& Val) { NewRow.OverrideCharacterSoundSet = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

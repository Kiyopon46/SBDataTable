#include "Importer/FSBCharacterStanceTableImporter.h"
#include "SBCharacterStanceTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterStanceTableImporter"

FString FSBCharacterStanceTableImporter::GetDataTableName() const
{
    return "CharacterStanceTable";
}

TFunction<void()> FSBCharacterStanceTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterStanceTableImporter::GetRowStruct() const
{
    return FSBCharacterStanceTableProperty::StaticStruct();
}

void FSBCharacterStanceTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterStanceTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombatType"), RowName, [&](const FString& Val) { NewRow.CombatType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bGroupAttacker"), RowName, [&](bool Val) { NewRow.bGroupAttacker = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDetectCloakingTarget"), RowName, [&](bool Val) { NewRow.bDetectCloakingTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("BoneBlendType"), RowName, [&](const FString& Val) { NewRow.BoneBlendType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Condition_DestroyCollisionGroupArray"), RowName, [&](const TArray<FString>& Val) { NewRow.Condition_DestroyCollisionGroupArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_ActorStat"), RowName, [&](const FString& Val) { NewRow.Condition_ActorStat = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_ActorStatCheck"), RowName, [&](const FString& Val) { NewRow.Condition_ActorStatCheck = Val; });
        TryApplyIntField(RowDataObject, TEXT("Condition_ActorStatCheckValue"), RowName, [&](int32 Val) { NewRow.Condition_ActorStatCheckValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_DeactiveActorState1"), RowName, [&](const FString& Val) { NewRow.Condition_DeactiveActorState1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_DeactiveActorState2"), RowName, [&](const FString& Val) { NewRow.Condition_DeactiveActorState2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_DeactiveActorState3"), RowName, [&](const FString& Val) { NewRow.Condition_DeactiveActorState3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_DeactiveActorState4"), RowName, [&](const FString& Val) { NewRow.Condition_DeactiveActorState4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_DeactiveActorState5"), RowName, [&](const FString& Val) { NewRow.Condition_DeactiveActorState5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_BattleMode"), RowName, [&](const FString& Val) { NewRow.Condition_BattleMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_Jumping"), RowName, [&](const FString& Val) { NewRow.Condition_Jumping = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_Swimming"), RowName, [&](const FString& Val) { NewRow.Condition_Swimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_EventMoving"), RowName, [&](const FString& Val) { NewRow.Condition_EventMoving = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_ChildGuideAction"), RowName, [&](const FString& Val) { NewRow.Condition_ChildGuideAction = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Condition_ActiveEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.Condition_ActiveEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Condition_NoneEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.Condition_NoneEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_PressCommandKey1"), RowName, [&](const FString& Val) { NewRow.Condition_PressCommandKey1 = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bActiveCheck_PressCommandKey1"), RowName, [&](bool Val) { NewRow.bActiveCheck_PressCommandKey1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_PressCommandKey2"), RowName, [&](const FString& Val) { NewRow.Condition_PressCommandKey2 = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bActiveCheck_PressCommandKey2"), RowName, [&](bool Val) { NewRow.bActiveCheck_PressCommandKey2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_WeaponEquipmentAlias"), RowName, [&](const FString& Val) { NewRow.Condition_WeaponEquipmentAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_SecondaryWeaponEquipmentAlias"), RowName, [&](const FString& Val) { NewRow.Condition_SecondaryWeaponEquipmentAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_ThirdlyWeaponEquipmentAlias"), RowName, [&](const FString& Val) { NewRow.Condition_ThirdlyWeaponEquipmentAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_FourthlyWeaponEquipmentAlias"), RowName, [&](const FString& Val) { NewRow.Condition_FourthlyWeaponEquipmentAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_MetaAI_TiredState"), RowName, [&](const FString& Val) { NewRow.Condition_MetaAI_TiredState = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bInfiniteStance"), RowName, [&](bool Val) { NewRow.bInfiniteStance = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CommandArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CommandArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWallHitPossible"), RowName, [&](bool Val) { NewRow.bWallHitPossible = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bImpossibleLockOn"), RowName, [&](bool Val) { NewRow.bImpossibleLockOn = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bImpossibleAutoLockOn"), RowName, [&](bool Val) { NewRow.bImpossibleAutoLockOn = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDropAttackTarget"), RowName, [&](bool Val) { NewRow.bDropAttackTarget = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBackStabTarget"), RowName, [&](bool Val) { NewRow.bBackStabTarget = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bForceFoldingWeapon"), RowName, [&](bool Val) { NewRow.bForceFoldingWeapon = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableCollision"), RowName, [&](bool Val) { NewRow.bDisableCollision = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableGravity"), RowName, [&](bool Val) { NewRow.bDisableGravity = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WalkSpeed"), RowName, [&](float Val) { NewRow.WalkSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RunSpeed"), RowName, [&](float Val) { NewRow.RunSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LockOnRunSpeed"), RowName, [&](float Val) { NewRow.LockOnRunSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LockOnWalkSpeed"), RowName, [&](float Val) { NewRow.LockOnWalkSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("JoggingRunSpeed"), RowName, [&](float Val) { NewRow.JoggingRunSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotateAnglePerSecond"), RowName, [&](float Val) { NewRow.RotateAnglePerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideCustomMovementMaxSpeed"), RowName, [&](float Val) { NewRow.OverrideCustomMovementMaxSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WalkSoundDecibel"), RowName, [&](float Val) { NewRow.WalkSoundDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WalkSoundLife"), RowName, [&](float Val) { NewRow.WalkSoundLife = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WalkSoundPeriod"), RowName, [&](float Val) { NewRow.WalkSoundPeriod = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RunSoundDecibel"), RowName, [&](float Val) { NewRow.RunSoundDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RunSoundLife"), RowName, [&](float Val) { NewRow.RunSoundLife = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RunSoundPeriod"), RowName, [&](float Val) { NewRow.RunSoundPeriod = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SprintSoundDecibel"), RowName, [&](float Val) { NewRow.SprintSoundDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SprintSoundLife"), RowName, [&](float Val) { NewRow.SprintSoundLife = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SprintSoundPeriod"), RowName, [&](float Val) { NewRow.SprintSoundPeriod = Val; });
        TryApplyFloatField(RowDataObject, TEXT("JumpSoundDecibel"), RowName, [&](float Val) { NewRow.JumpSoundDecibel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("JumpSoundLife"), RowName, [&](float Val) { NewRow.JumpSoundLife = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartShowPathWhenPeaceful"), RowName, [&](const FString& Val) { NewRow.StartShowPathWhenPeaceful = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartShowPathWhenBattle"), RowName, [&](const FString& Val) { NewRow.StartShowPathWhenBattle = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartEffect"), RowName, [&](const FString& Val) { NewRow.StartEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndShowPathWhenPeaceful"), RowName, [&](const FString& Val) { NewRow.EndShowPathWhenPeaceful = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndShowPathWhenBattle"), RowName, [&](const FString& Val) { NewRow.EndShowPathWhenBattle = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndEffect"), RowName, [&](const FString& Val) { NewRow.EndEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Peaceful_UpperBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Peaceful_UpperBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Peaceful_LowerBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Peaceful_LowerBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Battle_UpperBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Battle_UpperBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Battle_LowerBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Battle_LowerBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Groggy_UpperBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Groggy_UpperBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Groggy_LowerBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Groggy_LowerBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Down_UpperBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Down_UpperBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Down_LowerBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Down_LowerBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Dead_UpperBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Dead_UpperBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Dead_LowerBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Dead_LowerBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Airborne_UpperBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Airborne_UpperBody = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimSet_Airborne_LowerBody"), RowName, [&](const FString& Val) { NewRow.AnimSet_Airborne_LowerBody = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableMovingTransit"), RowName, [&](bool Val) { NewRow.bDisableMovingTransit = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableIdleAdditiveAnimWhenPeaceful"), RowName, [&](bool Val) { NewRow.bDisableIdleAdditiveAnimWhenPeaceful = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableIdleAdditiveAnimWhenBattle"), RowName, [&](bool Val) { NewRow.bDisableIdleAdditiveAnimWhenBattle = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverridePhysicsAsset"), RowName, [&](const FString& Val) { NewRow.OverridePhysicsAsset = Val; });
        TryApplyStringField(RowDataObject, TEXT("DeadSkillAlias"), RowName, [&](const FString& Val) { NewRow.DeadSkillAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DeadSkillPercentage"), RowName, [&](float Val) { NewRow.DeadSkillPercentage = Val; });
        TryApplyStringField(RowDataObject, TEXT("DeadSkillSelfDeadType"), RowName, [&](const FString& Val) { NewRow.DeadSkillSelfDeadType = Val; });
        TryApplyIntField(RowDataObject, TEXT("DeadSkillRewardDelayTime"), RowName, [&](int32 Val) { NewRow.DeadSkillRewardDelayTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("MountableEquipmentAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.MountableEquipmentAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bOptimizeWithSignificanceManager"), RowName, [&](bool Val) { NewRow.bOptimizeWithSignificanceManager = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bClearCommandInputWhenEnd"), RowName, [&](bool Val) { NewRow.bClearCommandInputWhenEnd = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

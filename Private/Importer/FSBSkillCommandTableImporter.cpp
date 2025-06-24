#include "Importer/FSBSkillCommandTableImporter.h"
#include "SBSkillCommandTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSkillCommandTableImporter"

FString FSBSkillCommandTableImporter::GetDataTableName() const
{
    return "SkillCommandTable";
}

TFunction<void()> FSBSkillCommandTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSkillCommandTableImporter::GetRowStruct() const
{
    return FSBSkillCommandTableProperty::StaticStruct();
}

void FSBSkillCommandTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSkillCommandTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandActionType"), RowName, [&](const FString& Val) { NewRow.CommandActionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillAlias"), RowName, [&](const FString& Val) { NewRow.SkillAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillPriorityAlias"), RowName, [&](const FString& Val) { NewRow.SkillPriorityAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombinationKey1CheckType"), RowName, [&](const FString& Val) { NewRow.CombinationKey1CheckType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombinationKey2CheckType"), RowName, [&](const FString& Val) { NewRow.CombinationKey2CheckType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombinationCrossUpCheckType"), RowName, [&](const FString& Val) { NewRow.CombinationCrossUpCheckType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombinationCrossDownCheckType"), RowName, [&](const FString& Val) { NewRow.CombinationCrossDownCheckType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombinationCrossLeftCheckType"), RowName, [&](const FString& Val) { NewRow.CombinationCrossLeftCheckType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CombinationCrossRightCheckType"), RowName, [&](const FString& Val) { NewRow.CombinationCrossRightCheckType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Command"), RowName, [&](const FString& Val) { NewRow.Command = Val; });
        TryApplyStringField(RowDataObject, TEXT("PressCheckCommand"), RowName, [&](const FString& Val) { NewRow.PressCheckCommand = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitResult"), RowName, [&](const FString& Val) { NewRow.HitResult = Val; });
        TryApplyFloatField(RowDataObject, TEXT("HitResultTime"), RowName, [&](float Val) { NewRow.HitResultTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("JustActiveTime"), RowName, [&](float Val) { NewRow.JustActiveTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InputTime"), RowName, [&](float Val) { NewRow.InputTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InputDuration"), RowName, [&](float Val) { NewRow.InputDuration = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState"), RowName, [&](const FString& Val) { NewRow.ActorState = Val; });
        TryApplyStringField(RowDataObject, TEXT("WeaponType"), RowName, [&](const FString& Val) { NewRow.WeaponType = Val; });
        TryApplyStringField(RowDataObject, TEXT("bJumping"), RowName, [&](const FString& Val) { NewRow.bJumping = Val; });
        TryApplyStringField(RowDataObject, TEXT("bWallRun"), RowName, [&](const FString& Val) { NewRow.bWallRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("bSprint"), RowName, [&](const FString& Val) { NewRow.bSprint = Val; });
        TryApplyStringField(RowDataObject, TEXT("bRun"), RowName, [&](const FString& Val) { NewRow.bRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("bLockOn"), RowName, [&](const FString& Val) { NewRow.bLockOn = Val; });
        TryApplyStringField(RowDataObject, TEXT("bFly"), RowName, [&](const FString& Val) { NewRow.bFly = Val; });
        TryApplyStringField(RowDataObject, TEXT("bSwimming"), RowName, [&](const FString& Val) { NewRow.bSwimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("bUWSwimming"), RowName, [&](const FString& Val) { NewRow.bUWSwimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("bFirstSwimming"), RowName, [&](const FString& Val) { NewRow.bFirstSwimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("bEventMoving"), RowName, [&](const FString& Val) { NewRow.bEventMoving = Val; });
        TryApplyStringField(RowDataObject, TEXT("bInBreakfallRange"), RowName, [&](const FString& Val) { NewRow.bInBreakfallRange = Val; });
        TryApplyStringField(RowDataObject, TEXT("bTachyGaugeMax"), RowName, [&](const FString& Val) { NewRow.bTachyGaugeMax = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckActiveEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckActiveEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckActiveNoneEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckActiveNoneEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputType"), RowName, [&](const FString& Val) { NewRow.InputType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stance"), RowName, [&](const FString& Val) { NewRow.Stance = Val; });
        TryApplyStringField(RowDataObject, TEXT("BulletItemAlias"), RowName, [&](const FString& Val) { NewRow.BulletItemAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("NextComboCommandArray"), RowName, [&](const TArray<FString>& Val) { NewRow.NextComboCommandArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckTargetFilter"), RowName, [&](bool Val) { NewRow.bCheckTargetFilter = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bPressInputTypeWhenNoOtherCommand"), RowName, [&](bool Val) { NewRow.bPressInputTypeWhenNoOtherCommand = Val; });
        TryApplyBoolField(RowDataObject, TEXT("GlobalCommand"), RowName, [&](bool Val) { NewRow.GlobalCommand = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckSameSkillActivation"), RowName, [&](bool Val) { NewRow.bCheckSameSkillActivation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckInputDirectionWhenHold"), RowName, [&](bool Val) { NewRow.bCheckInputDirectionWhenHold = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckInputDirectionAngle"), RowName, [&](bool Val) { NewRow.bCheckInputDirectionAngle = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bInputDirectionByActorLocalAxis"), RowName, [&](bool Val) { NewRow.bInputDirectionByActorLocalAxis = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinInputDirectionAngle"), RowName, [&](float Val) { NewRow.MinInputDirectionAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxInputDirectionAngle"), RowName, [&](float Val) { NewRow.MaxInputDirectionAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("HoldDuration"), RowName, [&](float Val) { NewRow.HoldDuration = Val; });
        TryApplyIntField(RowDataObject, TEXT("AICommandActivationRate"), RowName, [&](int32 Val) { NewRow.AICommandActivationRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetShowPath"), RowName, [&](const FString& Val) { NewRow.TargetShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandUIImage"), RowName, [&](const FString& Val) { NewRow.CommandUIImage = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReqEnergyType"), RowName, [&](const FString& Val) { NewRow.ReqEnergyType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ReqEnergyAmount"), RowName, [&](float Val) { NewRow.ReqEnergyAmount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableReservation"), RowName, [&](bool Val) { NewRow.bDisableReservation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBlockJumpAction"), RowName, [&](bool Val) { NewRow.bBlockJumpAction = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreLastUsedHoldSkill"), RowName, [&](bool Val) { NewRow.bIgnoreLastUsedHoldSkill = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bRemainToggleSprint"), RowName, [&](bool Val) { NewRow.bRemainToggleSprint = Val; });
        TryApplyStringField(RowDataObject, TEXT("DualSenseCheckType"), RowName, [&](const FString& Val) { NewRow.DualSenseCheckType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DualSenseTriggerEffectStateConditions"), RowName, [&](const TArray<FString>& Val) { NewRow.DualSenseTriggerEffectStateConditions = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bForceRootTrainingRoomLog"), RowName, [&](bool Val) { NewRow.bForceRootTrainingRoomLog = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bForceComboTrainingRoomLog"), RowName, [&](bool Val) { NewRow.bForceComboTrainingRoomLog = Val; });
        TryApplyIntField(RowDataObject, TEXT("DiableLockOnTargetFrameCount"), RowName, [&](int32 Val) { NewRow.DiableLockOnTargetFrameCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

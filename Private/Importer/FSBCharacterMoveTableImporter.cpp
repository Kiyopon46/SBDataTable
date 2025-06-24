#include "Importer/FSBCharacterMoveTableImporter.h"
#include "SBCharacterMoveTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterMoveTableImporter"

FString FSBCharacterMoveTableImporter::GetDataTableName() const
{
    return "CharacterMoveTable";
}

TFunction<void()> FSBCharacterMoveTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterMoveTableImporter::GetRowStruct() const
{
    return FSBCharacterMoveTableProperty::StaticStruct();
}

void FSBCharacterMoveTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterMoveTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetFilterAlias"), RowName, [&](const FString& Val) { NewRow.TargetFilterAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckCharacterWeight"), RowName, [&](bool Val) { NewRow.bCheckCharacterWeight = Val; });
        TryApplyStringField(RowDataObject, TEXT("RootMotionDataPath"), RowName, [&](const FString& Val) { NewRow.RootMotionDataPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RootMotionTimeScale"), RowName, [&](float Val) { NewRow.RootMotionTimeScale = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RootMotionStartTime"), RowName, [&](float Val) { NewRow.RootMotionStartTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RootMotionEndTime"), RowName, [&](float Val) { NewRow.RootMotionEndTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bRootMotionApplyPositionOnly"), RowName, [&](bool Val) { NewRow.bRootMotionApplyPositionOnly = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bRootMotionRealtimeLocalAxis"), RowName, [&](bool Val) { NewRow.bRootMotionRealtimeLocalAxis = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveType"), RowName, [&](const FString& Val) { NewRow.MoveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("PositionType"), RowName, [&](const FString& Val) { NewRow.PositionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("PositionInterpType"), RowName, [&](const FString& Val) { NewRow.PositionInterpType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMoveToSafeLocation"), RowName, [&](bool Val) { NewRow.bMoveToSafeLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("PositionInterpCurveDataPath"), RowName, [&](const FString& Val) { NewRow.PositionInterpCurveDataPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("PositionInterpCurveRealTime"), RowName, [&](bool Val) { NewRow.PositionInterpCurveRealTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("StaticMoveZVAlueCurveDataPath"), RowName, [&](const FString& Val) { NewRow.StaticMoveZVAlueCurveDataPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("StaticMoveZVAlueCurveRealTime"), RowName, [&](bool Val) { NewRow.StaticMoveZVAlueCurveRealTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveOffsetCurveDataPath"), RowName, [&](const FString& Val) { NewRow.MoveOffsetCurveDataPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("PositionDirectionAxis"), RowName, [&](const FString& Val) { NewRow.PositionDirectionAxis = Val; });
        TryApplyStringField(RowDataObject, TEXT("LinkSocketName"), RowName, [&](const FString& Val) { NewRow.LinkSocketName = Val; });
        TryApplyStringField(RowDataObject, TEXT("DefaultInputDirection"), RowName, [&](const FString& Val) { NewRow.DefaultInputDirection = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartDelayTime"), RowName, [&](float Val) { NewRow.StartDelayTime = Val; });
        TryApplyIntField(RowDataObject, TEXT("FrameDelayCount"), RowName, [&](int32 Val) { NewRow.FrameDelayCount = Val; });
        TryApplyFloatField(RowDataObject, TEXT("VelocityBlendInTime"), RowName, [&](float Val) { NewRow.VelocityBlendInTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("VelocityBlendOutTime"), RowName, [&](float Val) { NewRow.VelocityBlendOutTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveStartTime"), RowName, [&](float Val) { NewRow.MoveStartTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveEndTime"), RowName, [&](float Val) { NewRow.MoveEndTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Time"), RowName, [&](float Val) { NewRow.Time = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveTimePerDistance"), RowName, [&](float Val) { NewRow.MoveTimePerDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAxisYawOffset"), RowName, [&](float Val) { NewRow.MoveAxisYawOffset = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ForwardValue"), RowName, [&](float Val) { NewRow.ForwardValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RightValue"), RowName, [&](float Val) { NewRow.RightValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UpValue"), RowName, [&](float Val) { NewRow.UpValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ForwardValueWhenNoTarget"), RowName, [&](float Val) { NewRow.ForwardValueWhenNoTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RightValueWhenNoTarget"), RowName, [&](float Val) { NewRow.RightValueWhenNoTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UpValueWhenNoTarget"), RowName, [&](float Val) { NewRow.UpValueWhenNoTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("KeepFallingTime"), RowName, [&](float Val) { NewRow.KeepFallingTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LimitApproachDistance"), RowName, [&](float Val) { NewRow.LimitApproachDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationStartTime"), RowName, [&](float Val) { NewRow.RotationStartTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationEndTime"), RowName, [&](float Val) { NewRow.RotationEndTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("RotationType"), RowName, [&](const FString& Val) { NewRow.RotationType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RotationDirectionType"), RowName, [&](const FString& Val) { NewRow.RotationDirectionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RotationInterpCurveDataPath"), RowName, [&](const FString& Val) { NewRow.RotationInterpCurveDataPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationYawValue"), RowName, [&](float Val) { NewRow.RotationYawValue = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIndependentRotation"), RowName, [&](bool Val) { NewRow.bIndependentRotation = Val; });
        TryApplyStringField(RowDataObject, TEXT("CollisionCheckBoneNameWhenLinkFrom"), RowName, [&](const FString& Val) { NewRow.CollisionCheckBoneNameWhenLinkFrom = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DistanceToIgnoreRotationLimitAngle"), RowName, [&](float Val) { NewRow.DistanceToIgnoreRotationLimitAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationLeftLimitAngle"), RowName, [&](float Val) { NewRow.RotationLeftLimitAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationRightLimitAngle"), RowName, [&](float Val) { NewRow.RotationRightLimitAngle = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckFinalRotationLimitAngle"), RowName, [&](bool Val) { NewRow.bCheckFinalRotationLimitAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("YawValue"), RowName, [&](float Val) { NewRow.YawValue = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreCollision"), RowName, [&](bool Val) { NewRow.bIgnoreCollision = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMoveIgnoreTargetCharacter"), RowName, [&](bool Val) { NewRow.bMoveIgnoreTargetCharacter = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bIgnoreWorldStaticWhenLinkTo"), RowName, [&](bool Val) { NewRow.bIgnoreWorldStaticWhenLinkTo = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSaveTransform"), RowName, [&](bool Val) { NewRow.bSaveTransform = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenCollision"), RowName, [&](bool Val) { NewRow.bStopWhenCollision = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenWorldStaticCollision"), RowName, [&](bool Val) { NewRow.bStopWhenWorldStaticCollision = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenClif"), RowName, [&](bool Val) { NewRow.bStopWhenClif = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenOnWater"), RowName, [&](bool Val) { NewRow.bStopWhenOnWater = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenBlockingFall"), RowName, [&](bool Val) { NewRow.bStopWhenBlockingFall = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCheckRuleMoveBlockArea"), RowName, [&](bool Val) { NewRow.bCheckRuleMoveBlockArea = Val; });
        TryApplyStringField(RowDataObject, TEXT("RuleMoveBlockAreaApplyToTarget"), RowName, [&](const FString& Val) { NewRow.RuleMoveBlockAreaApplyToTarget = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenInvalidTarget"), RowName, [&](bool Val) { NewRow.bStopWhenInvalidTarget = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopWhenInvalidNavigation"), RowName, [&](bool Val) { NewRow.bStopWhenInvalidNavigation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAllowWhenEventMove"), RowName, [&](bool Val) { NewRow.bAllowWhenEventMove = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWallHit"), RowName, [&](bool Val) { NewRow.bWallHit = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WallHitStartTime"), RowName, [&](float Val) { NewRow.WallHitStartTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WallHitEndTime"), RowName, [&](float Val) { NewRow.WallHitEndTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bTargetMovedBack"), RowName, [&](bool Val) { NewRow.bTargetMovedBack = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bOnGround"), RowName, [&](bool Val) { NewRow.bOnGround = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bZeroVelocityWhenEnd"), RowName, [&](bool Val) { NewRow.bZeroVelocityWhenEnd = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bZeroGravity"), RowName, [&](bool Val) { NewRow.bZeroGravity = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bOverrideAcceleration"), RowName, [&](bool Val) { NewRow.bOverrideAcceleration = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAllowInvalidNavigation"), RowName, [&](bool Val) { NewRow.bAllowInvalidNavigation = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LimitJumpHeight"), RowName, [&](float Val) { NewRow.LimitJumpHeight = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWithDeactiveLinkToWhenLinkFrom"), RowName, [&](bool Val) { NewRow.bWithDeactiveLinkToWhenLinkFrom = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStartLocationOnGround"), RowName, [&](bool Val) { NewRow.bStartLocationOnGround = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd_UnderWater"), RowName, [&](const FString& Val) { NewRow.ConditionEnd_UnderWater = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEnd_Swimming"), RowName, [&](const FString& Val) { NewRow.ConditionEnd_Swimming = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("PathWay"), RowName, [&](const TArray<FString>& Val) { NewRow.PathWay = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

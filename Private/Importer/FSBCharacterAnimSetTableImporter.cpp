#include "Importer/FSBCharacterAnimSetTableImporter.h"
#include "SBCharacterAnimSetTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterAnimSetTableImporter"

FString FSBCharacterAnimSetTableImporter::GetDataTableName() const
{
    return "CharacterAnimSetTable";
}

TFunction<void()> FSBCharacterAnimSetTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterAnimSetTableImporter::GetRowStruct() const
{
    return FSBCharacterAnimSetTableProperty::StaticStruct();
}

void FSBCharacterAnimSetTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterAnimSetTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunBlendSpace"), RowName, [&](const FString& Val) { NewRow.RunBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunTiltBlendSpace"), RowName, [&](const FString& Val) { NewRow.RunTiltBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleAnimType"), RowName, [&](const FString& Val) { NewRow.IdleAnimType = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnSprintBlendSpace"), RowName, [&](const FString& Val) { NewRow.LockOnSprintBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("BlockMoveBlendSpace"), RowName, [&](const FString& Val) { NewRow.BlockMoveBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("AimOffsetBlendSpace"), RowName, [&](const FString& Val) { NewRow.AimOffsetBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("SelfieBlendSpace"), RowName, [&](const FString& Val) { NewRow.SelfieBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("WallRun"), RowName, [&](const FString& Val) { NewRow.WallRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnFall"), RowName, [&](const FString& Val) { NewRow.LockOnFall = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRunBlendSpace"), RowName, [&](const FString& Val) { NewRow.LockOnRunBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("FlyingBlendSpace"), RowName, [&](const FString& Val) { NewRow.FlyingBlendSpace = Val; });
        TryApplyStringField(RowDataObject, TEXT("FlyingStart"), RowName, [&](const FString& Val) { NewRow.FlyingStart = Val; });
        TryApplyStringField(RowDataObject, TEXT("FlyingToFall"), RowName, [&](const FString& Val) { NewRow.FlyingToFall = Val; });
        TryApplyStringField(RowDataObject, TEXT("FlyingToIdle"), RowName, [&](const FString& Val) { NewRow.FlyingToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("Fall"), RowName, [&](const FString& Val) { NewRow.Fall = Val; });
        TryApplyStringField(RowDataObject, TEXT("Sprint"), RowName, [&](const FString& Val) { NewRow.Sprint = Val; });
        TryApplyStringField(RowDataObject, TEXT("Jump"), RowName, [&](const FString& Val) { NewRow.Jump = Val; });
        TryApplyStringField(RowDataObject, TEXT("Jump2"), RowName, [&](const FString& Val) { NewRow.Jump2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Jump3"), RowName, [&](const FString& Val) { NewRow.Jump3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpFront"), RowName, [&](const FString& Val) { NewRow.JumpFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpFront2"), RowName, [&](const FString& Val) { NewRow.JumpFront2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpFront3"), RowName, [&](const FString& Val) { NewRow.JumpFront3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("WallJump"), RowName, [&](const FString& Val) { NewRow.WallJump = Val; });
        TryApplyStringField(RowDataObject, TEXT("WallRunJump"), RowName, [&](const FString& Val) { NewRow.WallRunJump = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoubleJump"), RowName, [&](const FString& Val) { NewRow.DoubleJump = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoubleJump2"), RowName, [&](const FString& Val) { NewRow.DoubleJump2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoubleJump3"), RowName, [&](const FString& Val) { NewRow.DoubleJump3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoubleJumpFront"), RowName, [&](const FString& Val) { NewRow.DoubleJumpFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoubleJumpFront2"), RowName, [&](const FString& Val) { NewRow.DoubleJumpFront2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoubleJumpFront3"), RowName, [&](const FString& Val) { NewRow.DoubleJumpFront3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpToIdle"), RowName, [&](const FString& Val) { NewRow.JumpToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpToSprint"), RowName, [&](const FString& Val) { NewRow.JumpToSprint = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpToSprintShort"), RowName, [&](const FString& Val) { NewRow.JumpToSprintShort = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpToWalk"), RowName, [&](const FString& Val) { NewRow.JumpToWalk = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpToRun"), RowName, [&](const FString& Val) { NewRow.JumpToRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpHighToRun"), RowName, [&](const FString& Val) { NewRow.JumpHighToRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpHighToIdle"), RowName, [&](const FString& Val) { NewRow.JumpHighToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("JumpHighToWalk"), RowName, [&](const FString& Val) { NewRow.JumpHighToWalk = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunToIdle_L"), RowName, [&](const FString& Val) { NewRow.RunToIdle_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunToIdle_R"), RowName, [&](const FString& Val) { NewRow.RunToIdle_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunToIdle"), RowName, [&](const FString& Val) { NewRow.RunToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("WalkToIdle_L"), RowName, [&](const FString& Val) { NewRow.WalkToIdle_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("WalkToIdle_R"), RowName, [&](const FString& Val) { NewRow.WalkToIdle_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("WalkToIdle"), RowName, [&](const FString& Val) { NewRow.WalkToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShortMoveToIdle_L"), RowName, [&](const FString& Val) { NewRow.ShortMoveToIdle_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShortMoveToIdle_R"), RowName, [&](const FString& Val) { NewRow.ShortMoveToIdle_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShortMoveToIdle"), RowName, [&](const FString& Val) { NewRow.ShortMoveToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartSprint"), RowName, [&](const FString& Val) { NewRow.StartSprint = Val; });
        TryApplyStringField(RowDataObject, TEXT("SprintToIdle"), RowName, [&](const FString& Val) { NewRow.SprintToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("SprintToRun"), RowName, [&](const FString& Val) { NewRow.SprintToRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunStart"), RowName, [&](const FString& Val) { NewRow.RunStart = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunStartAfterEvade"), RowName, [&](const FString& Val) { NewRow.RunStartAfterEvade = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunTurn_L"), RowName, [&](const FString& Val) { NewRow.RunTurn_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("RunTurn_R"), RowName, [&](const FString& Val) { NewRow.RunTurn_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("WalkTurn_L"), RowName, [&](const FString& Val) { NewRow.WalkTurn_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("WalkTurn_R"), RowName, [&](const FString& Val) { NewRow.WalkTurn_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleTurn_L"), RowName, [&](const FString& Val) { NewRow.IdleTurn_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleTurn_R"), RowName, [&](const FString& Val) { NewRow.IdleTurn_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleTurnToWalk_L"), RowName, [&](const FString& Val) { NewRow.IdleTurnToWalk_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleTurnToWalk_R"), RowName, [&](const FString& Val) { NewRow.IdleTurnToWalk_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("SprintTurn"), RowName, [&](const FString& Val) { NewRow.SprintTurn = Val; });
        TryApplyStringField(RowDataObject, TEXT("SprintTurn_L"), RowName, [&](const FString& Val) { NewRow.SprintTurn_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpNoMoving"), RowName, [&](const FString& Val) { NewRow.LockOnJumpNoMoving = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnDoubleJumpNoMoving"), RowName, [&](const FString& Val) { NewRow.LockOnDoubleJumpNoMoving = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpFront"), RowName, [&](const FString& Val) { NewRow.LockOnJumpFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpLeft"), RowName, [&](const FString& Val) { NewRow.LockOnJumpLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpRight"), RowName, [&](const FString& Val) { NewRow.LockOnJumpRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpBack"), RowName, [&](const FString& Val) { NewRow.LockOnJumpBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnDoubleJumpFront"), RowName, [&](const FString& Val) { NewRow.LockOnDoubleJumpFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnDoubleJumpLeft"), RowName, [&](const FString& Val) { NewRow.LockOnDoubleJumpLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnDoubleJumpRight"), RowName, [&](const FString& Val) { NewRow.LockOnDoubleJumpRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnDoubleJumpBack"), RowName, [&](const FString& Val) { NewRow.LockOnDoubleJumpBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToIdleFront"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToIdleFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToIdleBack"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToIdleBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToIdleLeft"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToIdleLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToIdleRight"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToIdleRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToRunFront"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToRunFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToRunBack"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToRunBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToRunLeft"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToRunLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnJumpToRunRight"), RowName, [&](const FString& Val) { NewRow.LockOnJumpToRunRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartSprintFront"), RowName, [&](const FString& Val) { NewRow.LockOnStartSprintFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartSprintBack"), RowName, [&](const FString& Val) { NewRow.LockOnStartSprintBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartSprintLeft"), RowName, [&](const FString& Val) { NewRow.LockOnStartSprintLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartSprintRight"), RowName, [&](const FString& Val) { NewRow.LockOnStartSprintRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnGuardRotationR"), RowName, [&](const FString& Val) { NewRow.LockOnGuardRotationR = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnGuardRotationL"), RowName, [&](const FString& Val) { NewRow.LockOnGuardRotationL = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRotationR"), RowName, [&](const FString& Val) { NewRow.LockOnRotationR = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRotationL"), RowName, [&](const FString& Val) { NewRow.LockOnRotationL = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatRotationR"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatRotationR = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatRotationL"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatRotationL = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatTurn_L"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatTurn_L = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatTurn_R"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatTurn_R = Val; });
        TryApplyStringField(RowDataObject, TEXT("UnLockOnAtChat"), RowName, [&](const FString& Val) { NewRow.UnLockOnAtChat = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartRunFront"), RowName, [&](const FString& Val) { NewRow.LockOnStartRunFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartRunBack"), RowName, [&](const FString& Val) { NewRow.LockOnStartRunBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartRunLeft"), RowName, [&](const FString& Val) { NewRow.LockOnStartRunLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnStartRunRight"), RowName, [&](const FString& Val) { NewRow.LockOnStartRunRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRunToIdleFront"), RowName, [&](const FString& Val) { NewRow.LockOnRunToIdleFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRunToIdleBack"), RowName, [&](const FString& Val) { NewRow.LockOnRunToIdleBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRunToIdleLeft"), RowName, [&](const FString& Val) { NewRow.LockOnRunToIdleLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnRunToIdleRight"), RowName, [&](const FString& Val) { NewRow.LockOnRunToIdleRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleFrontRFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleFrontRFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleBackRFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleBackRFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleLeftRFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleLeftRFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleRightRFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleRightRFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleFrontLFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleFrontLFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleBackLFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleBackLFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleLeftLFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleLeftLFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnAtChatMoveToIdleRightLFront"), RowName, [&](const FString& Val) { NewRow.LockOnAtChatMoveToIdleRightLFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnSprintToIdleFront"), RowName, [&](const FString& Val) { NewRow.LockOnSprintToIdleFront = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnSprintToIdleBack"), RowName, [&](const FString& Val) { NewRow.LockOnSprintToIdleBack = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnSprintToIdleLeft"), RowName, [&](const FString& Val) { NewRow.LockOnSprintToIdleLeft = Val; });
        TryApplyStringField(RowDataObject, TEXT("LockOnSprintToIdleRight"), RowName, [&](const FString& Val) { NewRow.LockOnSprintToIdleRight = Val; });
        TryApplyStringField(RowDataObject, TEXT("CliffReaction"), RowName, [&](const FString& Val) { NewRow.CliffReaction = Val; });
        TryApplyStringField(RowDataObject, TEXT("BlockWallFrontRun"), RowName, [&](const FString& Val) { NewRow.BlockWallFrontRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("BlockWallFrontWalk"), RowName, [&](const FString& Val) { NewRow.BlockWallFrontWalk = Val; });
        TryApplyStringField(RowDataObject, TEXT("BlockWallFrontSprint"), RowName, [&](const FString& Val) { NewRow.BlockWallFrontSprint = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGround"), RowName, [&](const FString& Val) { NewRow.HuddleUpGround = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundHigh"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundHigh = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpFalling"), RowName, [&](const FString& Val) { NewRow.HuddleUpFalling = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundToLow"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundToLow = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundHighToLow"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundHighToLow = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpFallingHigh"), RowName, [&](const FString& Val) { NewRow.HuddleUpFallingHigh = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpSideRod"), RowName, [&](const FString& Val) { NewRow.HuddleUpSideRod = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpSideRodWallless"), RowName, [&](const FString& Val) { NewRow.HuddleUpSideRodWallless = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundType2ToLow"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundType2ToLow = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundType2"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundType2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundType3ToLow"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundType3ToLow = Val; });
        TryApplyStringField(RowDataObject, TEXT("HuddleUpGroundType3"), RowName, [&](const FString& Val) { NewRow.HuddleUpGroundType3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartFallToLowDist"), RowName, [&](const FString& Val) { NewRow.StartFallToLowDist = Val; });
        TryApplyStringField(RowDataObject, TEXT("FallToLowDistToRun"), RowName, [&](const FString& Val) { NewRow.FallToLowDistToRun = Val; });
        TryApplyStringField(RowDataObject, TEXT("FallToLowDistToIdle"), RowName, [&](const FString& Val) { NewRow.FallToLowDistToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("FallToSwim"), RowName, [&](const FString& Val) { NewRow.FallToSwim = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroundToSwim"), RowName, [&](const FString& Val) { NewRow.GroundToSwim = Val; });
        TryApplyStringField(RowDataObject, TEXT("UnderWaterToWaterLine"), RowName, [&](const FString& Val) { NewRow.UnderWaterToWaterLine = Val; });
        TryApplyStringField(RowDataObject, TEXT("WaterLineToUnderWater"), RowName, [&](const FString& Val) { NewRow.WaterLineToUnderWater = Val; });
        TryApplyStringField(RowDataObject, TEXT("WaterLineToUnderWaterFail"), RowName, [&](const FString& Val) { NewRow.WaterLineToUnderWaterFail = Val; });
        TryApplyStringField(RowDataObject, TEXT("SwimToGround"), RowName, [&](const FString& Val) { NewRow.SwimToGround = Val; });
        TryApplyStringField(RowDataObject, TEXT("SwimJump"), RowName, [&](const FString& Val) { NewRow.SwimJump = Val; });
        TryApplyStringField(RowDataObject, TEXT("SwimTurn"), RowName, [&](const FString& Val) { NewRow.SwimTurn = Val; });
        TryApplyStringField(RowDataObject, TEXT("UnderWaterSwimTurn"), RowName, [&](const FString& Val) { NewRow.UnderWaterSwimTurn = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroundToSlope"), RowName, [&](const FString& Val) { NewRow.GroundToSlope = Val; });
        TryApplyStringField(RowDataObject, TEXT("FallToSlope"), RowName, [&](const FString& Val) { NewRow.FallToSlope = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlopeJump"), RowName, [&](const FString& Val) { NewRow.SlopeJump = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlopeDoubleJump"), RowName, [&](const FString& Val) { NewRow.SlopeDoubleJump = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlopeToGround"), RowName, [&](const FString& Val) { NewRow.SlopeToGround = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlopeToFall"), RowName, [&](const FString& Val) { NewRow.SlopeToFall = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlopeJumpToLand"), RowName, [&](const FString& Val) { NewRow.SlopeJumpToLand = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartWalkSlidingSlip"), RowName, [&](const FString& Val) { NewRow.StartWalkSlidingSlip = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndWalkSlidingSlip"), RowName, [&](const FString& Val) { NewRow.EndWalkSlidingSlip = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight1Left"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight1Left = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight1Right"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight1Right = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight1Back"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight1Back = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight1Front"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight1Front = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight2Left"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight2Left = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight2Right"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight2Right = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight2Back"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight2Back = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandLight2Front"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandLight2Front = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong1Left"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong1Left = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong1Right"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong1Right = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong1Back"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong1Back = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong1Front"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong1Front = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong2Left"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong2Left = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong2Right"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong2Right = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong2Back"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong2Back = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitStandStrong2Front"), RowName, [&](const FString& Val) { NewRow.Custom_HitStandStrong2Front = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Groggy_Start"), RowName, [&](const FString& Val) { NewRow.Custom_Groggy_Start = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Groggy_Loop"), RowName, [&](const FString& Val) { NewRow.Custom_Groggy_Loop = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Groggy_End"), RowName, [&](const FString& Val) { NewRow.Custom_Groggy_End = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Airborne_Loop"), RowName, [&](const FString& Val) { NewRow.Custom_Airborne_Loop = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_KnockDown_Start_Front"), RowName, [&](const FString& Val) { NewRow.Custom_KnockDown_Start_Front = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_KnockDown_Start_Back"), RowName, [&](const FString& Val) { NewRow.Custom_KnockDown_Start_Back = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_KnockDown_Loop"), RowName, [&](const FString& Val) { NewRow.Custom_KnockDown_Loop = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_KnockDown_End"), RowName, [&](const FString& Val) { NewRow.Custom_KnockDown_End = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Caution_LeftToIdle"), RowName, [&](const FString& Val) { NewRow.Custom_Caution_LeftToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Caution_RightToIdle"), RowName, [&](const FString& Val) { NewRow.Custom_Caution_RightToIdle = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitSwordNormalLinkAttack1"), RowName, [&](const FString& Val) { NewRow.Custom_HitSwordNormalLinkAttack1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitSwordNormalFinishLinkAttack1"), RowName, [&](const FString& Val) { NewRow.Custom_HitSwordNormalFinishLinkAttack1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitSwordAirDropAttack1"), RowName, [&](const FString& Val) { NewRow.Custom_HitSwordAirDropAttack1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_HitSwordNormalBackStab1"), RowName, [&](const FString& Val) { NewRow.Custom_HitSwordNormalBackStab1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim1"), RowName, [&](const FString& Val) { NewRow.Custom_Anim1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim2"), RowName, [&](const FString& Val) { NewRow.Custom_Anim2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim3"), RowName, [&](const FString& Val) { NewRow.Custom_Anim3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim4"), RowName, [&](const FString& Val) { NewRow.Custom_Anim4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim5"), RowName, [&](const FString& Val) { NewRow.Custom_Anim5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim6"), RowName, [&](const FString& Val) { NewRow.Custom_Anim6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim7"), RowName, [&](const FString& Val) { NewRow.Custom_Anim7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim8"), RowName, [&](const FString& Val) { NewRow.Custom_Anim8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim9"), RowName, [&](const FString& Val) { NewRow.Custom_Anim9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim10"), RowName, [&](const FString& Val) { NewRow.Custom_Anim10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim11"), RowName, [&](const FString& Val) { NewRow.Custom_Anim11 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim12"), RowName, [&](const FString& Val) { NewRow.Custom_Anim12 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim13"), RowName, [&](const FString& Val) { NewRow.Custom_Anim13 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim14"), RowName, [&](const FString& Val) { NewRow.Custom_Anim14 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim15"), RowName, [&](const FString& Val) { NewRow.Custom_Anim15 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim16"), RowName, [&](const FString& Val) { NewRow.Custom_Anim16 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim17"), RowName, [&](const FString& Val) { NewRow.Custom_Anim17 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim18"), RowName, [&](const FString& Val) { NewRow.Custom_Anim18 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim19"), RowName, [&](const FString& Val) { NewRow.Custom_Anim19 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom_Anim20"), RowName, [&](const FString& Val) { NewRow.Custom_Anim20 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

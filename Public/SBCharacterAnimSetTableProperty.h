#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterAnimSetTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterAnimSetTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunTiltBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleAnimType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnSprintBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BlockMoveBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AimOffsetBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SelfieBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WallRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnFall;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRunBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FlyingBlendSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FlyingStart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FlyingToFall;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FlyingToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Fall;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Sprint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Jump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Jump2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Jump3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpFront2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpFront3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WallJump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WallRunJump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoubleJump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoubleJump2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoubleJump3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoubleJumpFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoubleJumpFront2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoubleJumpFront3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpToSprint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpToSprintShort;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpToWalk;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpToRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpHighToRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpHighToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString JumpHighToWalk;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunToIdle_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunToIdle_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WalkToIdle_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WalkToIdle_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WalkToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShortMoveToIdle_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShortMoveToIdle_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShortMoveToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartSprint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SprintToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SprintToRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunStart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunStartAfterEvade;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunTurn_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RunTurn_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WalkTurn_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WalkTurn_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleTurn_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleTurn_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleTurnToWalk_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleTurnToWalk_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SprintTurn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SprintTurn_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpNoMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnDoubleJumpNoMoving;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnDoubleJumpFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnDoubleJumpLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnDoubleJumpRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnDoubleJumpBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToIdleFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToIdleBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToIdleLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToIdleRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToRunFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToRunBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToRunLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnJumpToRunRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartSprintFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartSprintBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartSprintLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartSprintRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnGuardRotationR;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnGuardRotationL;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRotationR;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRotationL;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatRotationR;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatRotationL;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatTurn_L;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatTurn_R;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnLockOnAtChat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartRunFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartRunBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartRunLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnStartRunRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRunToIdleFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRunToIdleBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRunToIdleLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnRunToIdleRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleFrontRFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleBackRFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleLeftRFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleRightRFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleFrontLFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleBackLFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleLeftLFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnAtChatMoveToIdleRightLFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnSprintToIdleFront;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnSprintToIdleBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnSprintToIdleLeft;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LockOnSprintToIdleRight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CliffReaction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BlockWallFrontRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BlockWallFrontWalk;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BlockWallFrontSprint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundHigh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpFalling;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundToLow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundHighToLow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpFallingHigh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpSideRod;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpSideRodWallless;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundType2ToLow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundType3ToLow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HuddleUpGroundType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartFallToLowDist;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FallToLowDistToRun;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FallToLowDistToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FallToSwim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroundToSwim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnderWaterToWaterLine;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WaterLineToUnderWater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WaterLineToUnderWaterFail;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SwimToGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SwimJump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SwimTurn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnderWaterSwimTurn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroundToSlope;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FallToSlope;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlopeJump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlopeDoubleJump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlopeToGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlopeToFall;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlopeJumpToLand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartWalkSlidingSlip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndWalkSlidingSlip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight1Left;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight1Right;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight1Back;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight1Front;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight2Left;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight2Right;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight2Back;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandLight2Front;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong1Left;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong1Right;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong1Back;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong1Front;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong2Left;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong2Right;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong2Back;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitStandStrong2Front;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Groggy_Start;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Groggy_Loop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Groggy_End;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Airborne_Loop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_KnockDown_Start_Front;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_KnockDown_Start_Back;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_KnockDown_Loop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_KnockDown_End;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Caution_LeftToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Caution_RightToIdle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitSwordNormalLinkAttack1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitSwordNormalFinishLinkAttack1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitSwordAirDropAttack1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_HitSwordNormalBackStab1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim11;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim13;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim14;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim15;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim16;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim17;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim18;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim19;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom_Anim20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
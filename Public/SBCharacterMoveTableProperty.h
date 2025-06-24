#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterMoveTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterMoveTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckCharacterWeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RootMotionDataPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RootMotionTimeScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RootMotionStartTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RootMotionEndTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRootMotionApplyPositionOnly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRootMotionRealtimeLocalAxis;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PositionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PositionInterpType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMoveToSafeLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PositionInterpCurveDataPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool PositionInterpCurveRealTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StaticMoveZVAlueCurveDataPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StaticMoveZVAlueCurveRealTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveOffsetCurveDataPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PositionDirectionAxis;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LinkSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DefaultInputDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 FrameDelayCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float VelocityBlendInTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float VelocityBlendOutTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveStartTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveEndTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Time;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveTimePerDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAxisYawOffset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ForwardValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RightValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UpValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ForwardValueWhenNoTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RightValueWhenNoTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UpValueWhenNoTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float KeepFallingTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LimitApproachDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationStartTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationEndTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RotationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RotationDirectionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RotationInterpCurveDataPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationYawValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIndependentRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CollisionCheckBoneNameWhenLinkFrom;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DistanceToIgnoreRotationLimitAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationLeftLimitAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationRightLimitAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckFinalRotationLimitAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float YawValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMoveIgnoreTargetCharacter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreWorldStaticWhenLinkTo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSaveTransform;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenWorldStaticCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenClif;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenOnWater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenBlockingFall;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCheckRuleMoveBlockArea;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RuleMoveBlockAreaApplyToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenInvalidTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopWhenInvalidNavigation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAllowWhenEventMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWallHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WallHitStartTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WallHitEndTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bTargetMovedBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bOnGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bZeroVelocityWhenEnd;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bZeroGravity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bOverrideAcceleration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAllowInvalidNavigation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LimitJumpHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWithDeactiveLinkToWhenLinkFrom;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStartLocationOnGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd_UnderWater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd_Swimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> PathWay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
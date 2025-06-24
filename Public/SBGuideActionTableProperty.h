#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBGuideActionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBGuideActionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PathWayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ZoneEventsWhenStart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ZoneEventsWhenArrive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ZoneEventsWhenComplete;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TheaterWhenStart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TheaterWhenArrive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TheaterWhenComplete;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TheaterWhenMovePause;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceWhenStart;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceWhenArrive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceWhenComplete;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceWhenMovePause;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestTaskGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPlayerAggroCheck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPlayerMoveControl;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayerMoveAreaLimitDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayerRunLimitDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayerSprintLimitDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMoveStateControlByPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveStateFromForwardPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinDistanceFromForwardPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxDistanceFromForwardPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveStateFromBackwardPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinDistanceFromBackwardPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxDistanceFromBackwardPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bFixedTargetRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StopDistanceToPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MovePauseDistanceToPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMovePauseLookAtPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovePauseShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLoopMovePauseShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveResumeDistanceToPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartShowDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ArriveShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ArriveShowDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLoopArriveShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLookAtPlayerWhenArrive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideMaxSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCompleteLookAtPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CompleteWaitTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StanceAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUsePathfinding;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CompletedTimerWhenArrive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CompletedDistanceToPlayerWhenArrive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bFly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FlyMoveSpeedPow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FormationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableDroneUIIndicator;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
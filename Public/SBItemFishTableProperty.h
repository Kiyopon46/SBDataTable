#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemFishTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemFishTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishRarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bNikke;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Stamina;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RunAwayStaminaRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RunAwayDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PullSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PullHitAreaSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 FightingTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LiftUpBobberScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LiftUpCamStartLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LiftUpCamFinalLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishFinalLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionRewardGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RewardItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovePatternCurveDataPath1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MovePatternWeight1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovePatternCurveDataPath2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MovePatternWeight2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovePatternCurveDataPath3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MovePatternWeight3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovePatternCurveDataPath4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MovePatternWeight4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MovePatternCurveDataPath5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MovePatternWeight5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TimingPullArrowSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullGaugeReductionPerHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaStart1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaSize1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaStart2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaSize2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaStart3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaSize3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaStart4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaSize4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaStart5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TimingPullHitAreaSize5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
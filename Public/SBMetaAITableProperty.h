#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBMetaAITableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBMetaAITableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Job;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Appearance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> InitTagArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ValidThinkArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> BehaviorAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepNodeGroupIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableCollisionOverlap;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundIntervalTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundProbability;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseOnlyTagNode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLookAtOnly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LookAtType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtYawAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtPitchAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtOnceTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtCooltime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LookAtStopDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StopMoveDistanceWithPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StopMoveAngleWithPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StopMoveOnceTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StopMoveCoolTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableShoulderCharge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShoulderChargeShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehaviorCheckTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehaviorActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAroundCustomBehavior1_ShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehavior1_ActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAroundCustomBehavior2_ShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehavior2_ActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAroundCustomBehavior3_ShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehavior3_ActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAroundCustomBehavior4_ShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehavior4_ActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAroundCustomBehavior5_ShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MoveAroundCustomBehavior5_ActivationRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bInitZeroTiredness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSkillTargetFilterTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSkillTargetFilterTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMultipleTargets;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDynamicShapeScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinShapeScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxShapeScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float NearDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FarDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SortType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckHitStepTimeWhenSortParry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShapeForwardDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShapeRightDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ShapeUpDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetCheckShape;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetCheckValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetCheckValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetCheckValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NonActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NonActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NonActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NonActorState4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NonActorState5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorStat1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorStatCheck1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ActorStatCheckValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckMinAngleToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckMaxAngleToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableBlockingCheck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBlockingCheckWithTopLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bValidEngineHandle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckBattleMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckActiveEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckActiveNoneEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckActiveEffectAliasArrayWhenEasyMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckActiveNoneEffectAliasArrayWhenEasyMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float GroundHeightToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bSwimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bEncroachmentable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString bDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bNotSupportedZoneEventActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
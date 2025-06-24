#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventActorTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventActorTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCollisionHitToActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CollisionActorDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomEffectValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomEffectValueByFireElement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EventInterval;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DespawnDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetFilterExtentX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetFilterExtentY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetFilterCheckHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ScaleTickDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardSpawnFormationAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DestructionEvent_DelayMinTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DestructionEvent_DelayMaxTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestructionEvent_EffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestructionEvent_RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestructionEvent_RewardBucketType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestructionEvent_RewardOverrideSaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DestructionEvent_RewardRemoveItemWithResetZone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DestructionEvent_ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DestructionEvent_ZoneEventAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DestructionEvent_EffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DestructCountMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DestructionTimer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CountEventStepArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CountEventRewardGroupAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CountEventRewardBucketTypeArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CountEventEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CountEventZoneEventAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent1_RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent1_EffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent1_ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent2_RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent2_EffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent2_ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent3_RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent3_EffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent3_ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent4_RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent4_EffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent4_ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent5_RewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent5_EffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CountEvent5_ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
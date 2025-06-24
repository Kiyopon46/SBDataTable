#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZonePhaseEventTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZonePhaseEventTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhaseEventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveEventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StartEventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StartEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteEventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveZoneEventList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StartZoneEventList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteZoneEventList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhaseEventCompleteType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 PhaseEventCompleteValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextPhaseEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PhaseEventDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWithDestory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
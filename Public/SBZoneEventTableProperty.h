#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionCheckType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EventDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EventDelayMinTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EventDelayMaxTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IgnoreEventByPlayerDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FinishEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AddEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
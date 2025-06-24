#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventRequestPathWayTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventRequestPathWayTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelTargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PathWayAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
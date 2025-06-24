#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventItemActionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventItemActionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Item;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventAIDecoTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventAIDecoTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ValueKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ValueType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CustomValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CustomValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CustomValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
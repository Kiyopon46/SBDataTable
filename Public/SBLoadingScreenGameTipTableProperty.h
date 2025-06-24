#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBLoadingScreenGameTipTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBLoadingScreenGameTipTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TipGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
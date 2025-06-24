#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBConditionTriggerTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBConditionTriggerTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
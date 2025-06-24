#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBConditionGroupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBConditionGroupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Conditions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEq;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupEq1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupEq2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBMetaAIBehaviorTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBMetaAIBehaviorTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FindDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Interval;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AcitiveProbability;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TirednessPerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Condition_StartTiredness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_StartTiredness_OperationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Condition_EndTiredness;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition_EndTiredness_OperationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
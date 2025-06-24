#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBRestartRuleTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBRestartRuleTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MainLevelTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LookAtLevelTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SafetyDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OutsideLimitTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OutSideLevelSequence;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OutSideTheaterEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
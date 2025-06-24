#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBHintTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBHintTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DelayActivateTimeSec;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 LongTimeDelayActivateTimeSec;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HintMessage_StringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActivateZoneTriggerAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
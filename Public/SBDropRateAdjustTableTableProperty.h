#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBDropRateAdjustTableTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBDropRateAdjustTableTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RarityCommon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RarityUncommon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RarityRare;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RarityEpic;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RarityLegendary;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
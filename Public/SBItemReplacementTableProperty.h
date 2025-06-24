#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemReplacementTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemReplacementTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReplacementItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ReplacementItemAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UseRewardDirectOverride;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RewardDirectValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UseRewardMustAcquisitionOverride;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool RewardMustAcquisition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBRewardGroupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBRewardGroupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GiveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool MustAcquisition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemVisualAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemCategory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemCategoryTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemRarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DropType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DropRateRarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DropRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ItemMinCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ItemMaxCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StatParentDependency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ItemStatLevelMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ItemStatLevelMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 OverrideInteractionTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardUIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
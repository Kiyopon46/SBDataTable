#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBShopItemTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBShopItemTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShopType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NanosuitAliasForRecipe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 LimitedCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoneyItemAlias1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MoneyItemCount1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Discount_MoneyItemCount1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoneyItemAlias2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MoneyItemCount2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Discount_MoneyItemCount2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoneyItemAlias3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MoneyItemCount3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Discount_MoneyItemCount3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoneyItemAlias4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MoneyItemCount4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Discount_MoneyItemCount4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LinkedShopItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ForceDirtyRedDot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FriendShip;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
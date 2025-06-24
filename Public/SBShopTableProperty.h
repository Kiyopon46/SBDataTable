#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBShopTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBShopTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UnionLimitedItem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup_ApplyDiscount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CurrencyItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ShopItems;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RequiredFriendShipLevelUp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FriendShipLevelUpSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FriendShipLevelUpSubtitleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FriendShipLevelUpSubtitleDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FriendShipLevelUpSubtitleTitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FriendShipLevelUpSubtitleMessage;

};
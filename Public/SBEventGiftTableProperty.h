#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventGiftTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventGiftTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GiftType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemAmountList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemLevelList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
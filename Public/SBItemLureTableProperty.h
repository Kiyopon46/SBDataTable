#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemLureTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemLureTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory11;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd11;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishCategory12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BiteRateAdd12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WeightUp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
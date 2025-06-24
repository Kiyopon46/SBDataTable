#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBDifficultyStatGroupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBDifficultyStatGroupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DifficultyAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DifficultyStatGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValue8;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterLevelTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterLevelTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StatValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stat2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StatValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequiredItemAlias1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredItemAmount1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequiredItemAlias2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredItemAmount2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
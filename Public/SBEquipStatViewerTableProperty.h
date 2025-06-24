#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEquipStatViewerTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEquipStatViewerTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CalculatedStatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxValueInNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DisplayMaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DisplayMaxTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnhanceCharLevelType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DisplayEnhanceCharLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DisplayAlways;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DontDisplayUI;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DisplayDecimal;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Achievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
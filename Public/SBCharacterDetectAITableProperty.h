#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterDetectAITableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterDetectAITableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AISightSenseHorizontalAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AISightSenseVerticalAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AISightSenseNearDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AISightSenseVerticalDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AISightSenseIgnoreBlocking;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AISightSenseIgnoreBlockingWhenDetectTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIDetectCheckDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIObserveCheckDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIPursuitDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIPursuitFixedDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIPursuitVerticaDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIIncreaseAggroGaguePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIIncreaseDoubtAggroGaguePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIDecreaseLevel0AggroGaguePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AIDecreaseLevel1AggroGaguePerSecond;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
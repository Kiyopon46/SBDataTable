#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterWeightTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterWeightTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Small_MoveXY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Small_MoveZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Normal_MoveXY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Normal_MoveZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Medium_MoveXY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Medium_MoveZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Large_MoveXY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Large_MoveZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SuperLarge_MoveXY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SuperLarge_MoveZ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
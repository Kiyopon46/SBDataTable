#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBLevelGraphicsOptionsTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBLevelGraphicsOptionsTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FSR2QualityMode;

};
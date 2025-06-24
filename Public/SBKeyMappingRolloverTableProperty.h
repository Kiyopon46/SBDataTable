#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBKeyMappingRolloverTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBKeyMappingRolloverTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FirstKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SecondKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
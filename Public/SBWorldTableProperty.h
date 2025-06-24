#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBWorldTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBWorldTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UMapPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
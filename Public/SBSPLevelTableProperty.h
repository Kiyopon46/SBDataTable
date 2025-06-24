#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSPLevelTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSPLevelTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequiredSPExp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBIsolatedAreaTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBIsolatedAreaTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

};
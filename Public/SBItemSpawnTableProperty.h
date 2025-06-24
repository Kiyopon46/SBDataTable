#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemSpawnTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemSpawnTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBActorStatTextTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBActorStatTextTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CalculatedStatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TextType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBResourceCacheSequenceTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBResourceCacheSequenceTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestEpic;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomGroup1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
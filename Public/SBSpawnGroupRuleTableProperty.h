#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSpawnGroupRuleTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSpawnGroupRuleTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnGroupRuleAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SubGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SubGroupSelectItemCnt;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DuplicationPreventKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EventSpawnArray;

};
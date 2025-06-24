#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemConsumableTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemConsumableTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ConsumeImmidiate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConsumeCoolTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConsumeSkillAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConsumeEnergyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ConsumeEnergyAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool NotRemoveItem;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
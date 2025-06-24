#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBManualTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBManualTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ManualType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseAcquisitionSkillString;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DescStringKeyArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> MoviePathArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ImagePathArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupUnlockAchievementAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupUnlockConditionGroupAlias;

};
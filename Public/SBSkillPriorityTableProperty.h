#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSkillPriorityTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSkillPriorityTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillSlotType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> SkillAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemSkillEquipableTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemSkillEquipableTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemSkillEquipableAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Level;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AcquisitionSkillAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillCommandAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EquipEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> UnequipEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RequiredItemAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RequiredItemAmountArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
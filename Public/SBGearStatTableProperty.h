#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBGearStatTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBGearStatTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCategoryTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GearStatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorStatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectStatTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StatLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Rarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValueMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StatValueMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TextEffectName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TextEffectDesc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
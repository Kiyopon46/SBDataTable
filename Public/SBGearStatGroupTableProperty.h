#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBGearStatGroupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBGearStatGroupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCategoryTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GearStatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorStatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectStatTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
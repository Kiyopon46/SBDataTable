#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventActorEffectTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventActorEffectTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventorType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToCaster;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CasterTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventZoneEventActorControlTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventZoneEventActorControlTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneEventActorName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneEventActorControlType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DestructionTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableDestruction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
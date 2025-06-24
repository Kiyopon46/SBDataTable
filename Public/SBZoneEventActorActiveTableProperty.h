#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventActorActiveTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventActorActiveTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Active;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
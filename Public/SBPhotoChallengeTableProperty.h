#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBPhotoChallengeTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBPhotoChallengeTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetZoneEnvActorAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckBoxRatioX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CheckBoxRatioY;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LinkedQuestTaskAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExceptActorAlias;

};
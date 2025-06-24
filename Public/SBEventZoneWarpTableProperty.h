#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventZoneWarpTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventZoneWarpTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetWorld;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetZoneCamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetSpawnPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseRecoveryItems;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WarpDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FadeOutTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseCampCustomTargetPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
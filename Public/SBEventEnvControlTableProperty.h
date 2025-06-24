#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventEnvControlTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventEnvControlTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvControlType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetCamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Activate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AddProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SetStateProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ProgressSlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ProgressSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ProgressSpeedInterpTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CurrentProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EndProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
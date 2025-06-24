#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventAreaControlVolumeControlTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventAreaControlVolumeControlTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AreaControlVolume1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AreaControlVolume2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AreaControlVolume3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AreaControlVolume4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AreaControlVolume5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Activate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
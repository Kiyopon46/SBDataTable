#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventLaserControlTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventLaserControlTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LaserUniqueName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LaserGroupName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Activate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
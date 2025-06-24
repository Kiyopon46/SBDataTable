#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBPhotoModeMovementTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBPhotoModeMovementTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CameraType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Acceleration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Deceleration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAffectedByFOV;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FOVScaleMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FOVScaleMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
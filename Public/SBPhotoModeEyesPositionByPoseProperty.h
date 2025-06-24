#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBPhotoModeEyesPositionByPoseProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBPhotoModeEyesPositionByPoseProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PoseName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CameraType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EyesPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EyesPosition_Adam;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EyesPosition_Lily;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
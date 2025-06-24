#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBPhotoModeFacialAnimationTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBPhotoModeFacialAnimationTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhotoModeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CameraType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EyesPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
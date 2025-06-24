#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSocialAnimTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSocialAnimTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Motion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Stance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BlendIn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BlendOut;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
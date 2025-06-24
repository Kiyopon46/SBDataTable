#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBWorldMapTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBWorldMapTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PrevWorldMapAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextWorldMapAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExceptIsolatedAreaAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetImageBG;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetImageTitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InitiaImageSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 InitialZoomLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Size1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Speed1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Size2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Speed2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Size3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Speed3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnlockAchievementAlias;

};
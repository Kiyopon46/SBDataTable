#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneCampTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneCampTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Region;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RegionName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InGameUICampImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CoinSpawnPointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideCampDetectDistance_Max;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampDisplayType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LinkCampAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampDisplayLinkAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnableMapMakerCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WorldMapOverlapDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ForceCampTrophyAchievementForEnvState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
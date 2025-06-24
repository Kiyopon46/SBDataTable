#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCanTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCanTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringKeyTitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringKeyFunc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringKeyContent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Asset3D;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AssetMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DetectEnvSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AcquireEnvSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CollectionEnvSpawnAliases;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CollectionXList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CollectionYList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AchievementAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideDetectDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideAutoInteractionDistance;

};
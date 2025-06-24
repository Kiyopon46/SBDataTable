#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventItemTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventItemTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ControlType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString World;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventorType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnPointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SpawnItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnInfoAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnItemBucketType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EventDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckAchievements;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AcquireZoneEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseOverrideAutoInteraction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAutoInteraction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AutoInteractionDist;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
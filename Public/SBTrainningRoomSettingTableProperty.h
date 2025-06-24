#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBTrainningRoomSettingTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBTrainningRoomSettingTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RegionActorName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitRegionActorEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bInitApplyPlayerInfiniteEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlayerStartPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> PlayerStartEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlayerStartSkill;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnemyStartEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnemyNpcAIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnemyNpcSpawnPointPreFix;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnemyNpcReSpawnPointPreFix;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnemySpawnList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnemySpawnRotationTypeList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
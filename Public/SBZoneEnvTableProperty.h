#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEnvTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEnvTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateTagNameList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateEffectList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateZoneEventList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateConditionGroupList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateRewardGroupList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateCasterShowPathList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateProgressCountList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StateProgressChangeTagNameList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardSpawnBucketType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardOverrideSaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardSpawnFormationAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvObjectMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseAutoActivateCamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveEnterEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveLeaveEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProgressMaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> bProgressAlwaysUpdates;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProgressNotifyEventList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TriggerCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TriggerCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TriggerTrueEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TriggerFalseEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrueEnvState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FalseEnvState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionUpperHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionLowerHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionTargetRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionDotUIAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Interaction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bForceFoldInteraction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampObjectType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleCompareData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleDataType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleEq;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ScanDisplayType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float NikkeGoodsDetectDistance_Max;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> NikkeDefenseArea_EnemyEnter_Events;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> NikkeDefenseArea_EnemyEmpty_Events;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
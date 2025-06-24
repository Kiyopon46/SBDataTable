#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBNGPlusZoneEventSpawnTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBNGPlusZoneEventSpawnTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnPointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitActivate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CharacterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnRotationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnGroupRuleAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveSubProperty;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bResetZoneKeepObject;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString KeepObjResetTransformType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepObjApplyResetState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSaveWithBlackBoard;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSpawnToActive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DrawDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableDrawDistanceScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AlwaysTickDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepSBCharacterWhenActiveAreaControlVolume;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EventOnSpawning;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EventOnDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EventOnBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EventFirstTimeOnBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableActorTickAtSpawning;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool GoPathAfterSpawn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PathWay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardSpawnBucketType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardOverrideSaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bHidden;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AIGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AIGroupName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAIGroupLeader;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MetaAIAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MetaAI_InitThink;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MetaAI_SpecialBehaviorTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionTargetRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionDotUIAngle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionUpperHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionLowerHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OwnerRotationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableTransitZone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableTransitZoneByEnemyActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TransitStayZoneSaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AdjustInteractTargetPosType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Interaction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionsTrigger;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionTriggerEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionTriggerRunType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionTriggerExecType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckAchievements;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> bCheckAchievementNotOperate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckAchievementProgress;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ShopDataList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> SpawnEffectList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnRuleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RespawnIntervalTimeMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RespawnIntervalTimeMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleInputText1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleInputText2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleInputText3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleInputText4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> PuzzleInputTextList5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnPosition;
    //UPROPERTY(EditAnywhere, BlueprintReadWrite)
    //FVector SpawnPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldMapDisplayType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldMapDisplayTitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldMapDisplayDesc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldMapDisplayConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldMapIconTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WorldMapOverlapDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideCustomTrackNearDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DontCheckZAxisCustomTrackNear;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractionRelevantType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ObjectMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> InteractionDisable_Condition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractionDisable_ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMultiSpawnPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
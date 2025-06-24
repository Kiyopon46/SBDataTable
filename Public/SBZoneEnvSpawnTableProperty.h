#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEnvSpawnTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEnvSpawnTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ZoneList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvActorName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvBPPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnPointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitActivate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitEnvActiveState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitStateTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventTagName10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TagEventList10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardTagName10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString State_RewardGroup10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardSpawnFormationAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardSpawnBucketType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RewardOverrideSaveType;

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
    TArray<FString> ActiveEnterEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveLeaveEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LinkEnvSpawnList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetCamp;

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
    TArray<FString> InitProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> StartProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EndProgressValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProgressNotifyEventList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleCompareData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleDataType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PuzzleEq;

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
    TArray<FString> SequenceTagNameList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> OutTransitTheaterList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> OutTransitSequenceList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> OutTransitTemplatePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> OutTransitAttachTagNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveTheaterList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveSequenceList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveTemplatePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveAttachTagNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LoopSequenceList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LoopTemplatePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LoopAttachTagNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ForceLoopStopWhenChangeState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DontStopLoopSequenceAtDestoryOptionList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> UseTemplateTransformList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ToTargetStateInfoList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> PlayTransformOwnerTypeList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ShopDataList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bResetByWarpSafeLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResetFilterType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResetFilterCondition;

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
    bool bMaintainNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SaveMinIntervalByAutoActivateCamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ScanOverrideStencilValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideNikkeGoodsDetectDistanceMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> InteractionDisable_Condition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractionDisable_ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NikkeLostArticle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NikkeFriendlyNpc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
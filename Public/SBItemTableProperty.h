#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InventoryAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 InventoryPriority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NamePlural;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DescFunction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DescContent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Category;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CategoryTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Rarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IncludeDropPool;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StackAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MaxAmountOverrideActorStat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ChargeCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ChargeOverrideActorStat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AbleBroken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AblePrice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AbleDrop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RequireLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StudioAsset3D;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Asset3D;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Asset3DArg;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AssetZOffset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Asset3DScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Asset2D;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AlbumAsset2D;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpecialRewardAsset2D;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool FastNotifySpecialReward;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GainAllowShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AfterGainShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AfterGainShowParam;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActorBlockTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool InteractionImmidateUse;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InteractionDist;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AutoInteraction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AutoInteractionDist;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipableAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConsumableAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillEquipableAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipmentAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipmentAlias2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ApplyEquipType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BulletAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AutoCharacterLevelUpType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NotiType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ScanDisplayType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ScanDisplayGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WeightMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WeightMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LureAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMaintainNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaintainMaxAmountForFirstNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ValidConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
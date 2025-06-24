#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBGuideMessageTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBGuideMessageTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MessageType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DisplayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DisplayPositionX;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GuideStartType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StartValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GuideCompleteType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CompleteValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool CustomBool;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CustomAliases;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Command;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GuideCompleteAchievementAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GuideTimeOutAchievementAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GuideSkipAchievementAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CancelConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIActionRequestGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAffectedByVisibleOption;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ForceSlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DontShowInNewGamePlus;

};
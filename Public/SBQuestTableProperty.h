#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBQuestTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBQuestTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestUIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequestType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayRequestBoardType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextQuest;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleName_;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description_;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequestDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Report;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Reward;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FailAchievementCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FailConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FailConditionEventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FailConditionResultType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AvailableConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ValidConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AcquireSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AcquireSubtitleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AcquireSubtitleDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AcquireSubtitleTitle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AcquireSubtitleMessage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RequiredQuestArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AcquireEventArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteEventArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> QuestPathStartNodes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> QuestPathWorlds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AcquireEventActionTypeList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AcquireEventActionAliasList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMaintainNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
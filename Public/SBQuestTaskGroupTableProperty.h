#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBQuestTaskGroupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBQuestTaskGroupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskContainerArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActivateEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProgressEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> QuestPathStartNodes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> QuestPathWorlds;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> QuestPathAreas;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RestartRule;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowGreenDot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpUIDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpTargetCamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpTargetWorld;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpTargetLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpTargetRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpTargetSpawnPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpChoiceYesPlayTheater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpChoiceNoPlayTheater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
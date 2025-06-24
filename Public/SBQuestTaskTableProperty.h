#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBQuestTaskTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBQuestTaskTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MissionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OwnerFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TrackingTargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrackingConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CustomNameArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStr2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CustomInt;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CustomInt2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CustomFloat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConditionCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DescriptionUIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TaskConditionUIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool HideHUD;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskStartEventTypeList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskStartEventSpawnAliasList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskCompleteEventTypeList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskCompleteEventSpawnAliasList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskProgressEventTypeList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskProgressEventProgressCountList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TaskProgressEventSpawnAliasList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
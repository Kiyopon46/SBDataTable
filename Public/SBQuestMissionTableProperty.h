#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBQuestMissionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBQuestMissionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MissionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OwnerFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CustomValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConditionCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Radius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActivateEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProgressEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
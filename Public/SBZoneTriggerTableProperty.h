#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneTriggerTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneTriggerTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitActivate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TriggerType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TouchEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LeaveEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Condition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TriggerActorAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoingType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool InOutTrigger;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 InitialDoingCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IgnoreDoingCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActiveRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BoxExtent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IgnoreFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionObjectMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelTargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BlockExtraSprintDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
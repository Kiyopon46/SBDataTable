#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBConditionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBConditionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEq;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStr01;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStr02;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStr03;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckStrValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CheckValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheckStatCalcType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorTargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GameOptionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseActorTragetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FailNotifyMsg;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
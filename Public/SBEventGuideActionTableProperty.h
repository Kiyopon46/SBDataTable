#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventGuideActionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventGuideActionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FollowerTagNameArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FollowerStartDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StopGuideAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GuideActionAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
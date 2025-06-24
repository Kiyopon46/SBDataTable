#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventMetaAITableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventMetaAITableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MetaAIEventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpecialBehaviorTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AddTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ForceThink;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ForceThink_BehaviorAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
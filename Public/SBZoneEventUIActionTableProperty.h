#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventUIActionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventUIActionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIActionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UILogicType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIActionRequestIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DrawDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStrValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CustomStrValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventorType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bHUDInputLock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bGameMenuInputLock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
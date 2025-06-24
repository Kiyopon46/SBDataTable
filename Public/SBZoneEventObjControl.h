#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventObjControl.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventObjControl : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDataAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ObjectType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Activate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ObjectControlActionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RetargetSpawnPointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWithStorage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
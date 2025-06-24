#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBAIGroupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBAIGroupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MinGroupActorCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetShareCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TargetShareConditionValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxAttackerCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ReattackWaitingTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttackerSelectMethod;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ValidProjectileCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InvalidProjectileOffsetMinDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InvalidProjectileOffsetMaxDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CautionMinDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CautionMaxDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseMetaAIFormation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MetaAIFormationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bImmediatelyBattleAlarm;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
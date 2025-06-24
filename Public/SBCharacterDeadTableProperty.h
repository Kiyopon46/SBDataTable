#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterDeadTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterDeadTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DefaultDeadShowArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DefaultDeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DefaultDeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DefaultDeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAliasWhenDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StandDeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StandDeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StandDeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StandDeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Step0DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Step0DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Step0DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Step0DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Step1DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Step1DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Step1DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Step1DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Step2DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Step2DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Step2DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Step2DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Step3DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Step3DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Step3DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Step3DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Explosion1DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Explosion1DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Explosion1DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Explosion1DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Explosion2DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Explosion2DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Explosion2DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Explosion2DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom1DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom1DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom1DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom1DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom2DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom2DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom2DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom2DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom3DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom3DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom3DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom3DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom4DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom4DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom4DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom4DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom5DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom5DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom5DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom5DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom6DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom6DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom6DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom6DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom7DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom7DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom7DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom7DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom8DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom8DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom8DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom8DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom9DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom9DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom9DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom9DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Custom10DeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Custom10DeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Custom10DeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Custom10DeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DownDeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 DownDeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DownDeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DownDeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AirborneDeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AirborneDeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AirborneDeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AirborneDeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SwimmingDeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SwimmingDeadRewardDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool SwimmingDeadSkipDespawnShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SwimmingDeadUIDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AdditiveDeadShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEffectVolumeTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEffectVolumeTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitActivate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString VolumeType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveZoneAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnterEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AlwaysActiveEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount01;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList01;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount02;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList02;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount03;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList03;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount04;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList04;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PropertyData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResetTargetAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResetTargetState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseEveryZone;

};
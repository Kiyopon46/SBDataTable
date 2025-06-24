#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEffectVolumePropTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEffectVolumePropTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

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
    int32 ExecuteDeadCount05;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList05;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount06;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList06;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount07;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList07;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount08;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList08;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount09;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList09;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExecuteDeadCount10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeadCountEffectAliasList10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
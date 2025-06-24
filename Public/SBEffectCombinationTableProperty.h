#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEffectCombinationTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEffectCombinationTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Effect1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Effect1Count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepEffect1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Effect2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Effect2Count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepEffect2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Effect3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Effect3Count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepEffect3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Effect4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Effect4Count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepEffect4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Effect5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Effect5Count;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepEffect5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ResultEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
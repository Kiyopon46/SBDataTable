#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCreditTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCreditTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString VoiceLanguage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreditType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
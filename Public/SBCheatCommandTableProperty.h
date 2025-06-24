#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCheatCommandTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCheatCommandTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Distribution;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Tab;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TabName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Category;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CategoryName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CategoryStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DescStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Command;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IgnoreNotify;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bNoGuaranteeProgressExec;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
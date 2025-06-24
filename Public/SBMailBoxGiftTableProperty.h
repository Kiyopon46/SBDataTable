#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBMailBoxGiftTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBMailBoxGiftTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DescStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ReceivableConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnableMailBoxEnvSpawnList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventGiftAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MailImagePath;

};
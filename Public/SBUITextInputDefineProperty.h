#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBUITextInputDefineProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBUITextInputDefineProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Key;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Platform;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString text;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
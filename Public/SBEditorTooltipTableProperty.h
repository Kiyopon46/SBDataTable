#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEditorTooltipTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEditorTooltipTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Target;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FieldName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FieldNameArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
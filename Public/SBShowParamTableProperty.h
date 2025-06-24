#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBShowParamTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBShowParamTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UseCreateStaticMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CreateStaticMaterialElementIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CreateStaticMaterialInstanceIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
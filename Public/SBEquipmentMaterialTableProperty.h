#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEquipmentMaterialTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEquipmentMaterialTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 VariationIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaterialIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MaterialAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IconColorAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneLayerTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneLayerTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LayerName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ZoneList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
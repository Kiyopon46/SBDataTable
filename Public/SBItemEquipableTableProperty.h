#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemEquipableTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemEquipableTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GearType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BaseStatGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
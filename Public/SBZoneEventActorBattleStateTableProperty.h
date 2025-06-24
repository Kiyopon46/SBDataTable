#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventActorBattleStateTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventActorBattleStateTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool BattleState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UseForceFoldWeaponValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool FoldWeaponValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
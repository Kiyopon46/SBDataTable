#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSoundEquipmentSetTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSoundEquipmentSetTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipmentAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterSoundSetOverride;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterFootstepSetOverride;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SoundEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
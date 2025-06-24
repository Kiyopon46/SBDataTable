#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEventInteractCampTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEventInteractCampTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CampEnvSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowResetZoneUI;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DoingSaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SoundEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
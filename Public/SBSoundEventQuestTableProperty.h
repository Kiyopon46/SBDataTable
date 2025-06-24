#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSoundEventQuestTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSoundEventQuestTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestAcquireSoundEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestCompleteSoundEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
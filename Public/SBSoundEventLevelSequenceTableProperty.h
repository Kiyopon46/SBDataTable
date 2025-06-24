#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSoundEventLevelSequenceTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSoundEventLevelSequenceTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceBeginSoundEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BeginSoundEventDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceFinishSoundEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FinishSoundEventDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SoundMixPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
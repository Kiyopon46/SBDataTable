#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSoundAttenuationEventTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSoundAttenuationEventTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Editor_Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DialogAttenuationPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionVoiceAttenuationPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FootstepAttenuationPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
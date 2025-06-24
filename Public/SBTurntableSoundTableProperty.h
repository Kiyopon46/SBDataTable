#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBTurntableSoundTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBTurntableSoundTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NotifyAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MusicPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NoiseMusicPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ImagePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QNRTAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
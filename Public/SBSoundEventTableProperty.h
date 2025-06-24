#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSoundEventTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSoundEventTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MainBGMPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AmbientBGMPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SoundStateRule;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventBattleState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> IntParams;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SoundBasePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttachActorTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttachSocket;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttenuationEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
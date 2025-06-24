#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventLevelSeqTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventLevelSeqTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSeqAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequencePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AttachTagNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopEndFrame;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SequenceTemplatePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventorType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDontStopResetZone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSequenceContentsType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool StartMovementNone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool UseRandomSequence;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RandomLevelSequencePaths;

};
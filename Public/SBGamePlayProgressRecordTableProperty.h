#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBGamePlayProgressRecordTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBGamePlayProgressRecordTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestTaskGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestTaskType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DataAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Enable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Zone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractionKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractionValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RecordFilterType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DebugTargetCamp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DebugSpawnPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommands;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommands2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommands3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommands4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommandsForNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommandsForNewGamePlus2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommandsForNewGamePlus3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DebugCommandsForNewGamePlus4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
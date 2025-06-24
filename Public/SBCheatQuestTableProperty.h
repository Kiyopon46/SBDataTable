#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCheatQuestTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCheatQuestTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CheatProgressQuestCommandsTable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMaintainSubQuest;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartWorld;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartSpawnLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheatGroupCommands;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
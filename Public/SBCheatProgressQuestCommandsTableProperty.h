#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCheatProgressQuestCommandsTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCheatProgressQuestCommandsTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteQuestList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GamePlayProgressRecord;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 QuestPathIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 QuestPathNodeIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
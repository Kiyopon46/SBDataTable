#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBGamePlayProgressCheatTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBGamePlayProgressCheatTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PreCommand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot1NewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot2NewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot3NewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CommandSlot4NewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PostCommand;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
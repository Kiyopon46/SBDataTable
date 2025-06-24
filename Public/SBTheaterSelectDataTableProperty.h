#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBTheaterSelectDataTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBTheaterSelectDataTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SelectDataName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Conditions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DesignType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleMessageText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TextVisibleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextTaskTagName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SelectDataPriority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InteractionGraphExec;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseInputCancel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestSymbolType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> QuestSymbol_VisibilityConditionGorup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bForceLock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableRelevantDot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SelectedMessagePopupText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
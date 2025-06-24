#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBUITutorialTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBUITutorialTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DescStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBlockNavigation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnableInputAliases;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> BlockingWidgetEventNameList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NextTutorialAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OpenUILogicType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OpenUIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CompleteWidgetEventName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CompleteAchievementAlias;

};
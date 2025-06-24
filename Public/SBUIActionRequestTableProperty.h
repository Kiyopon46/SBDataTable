#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBUIActionRequestTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBUIActionRequestTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool BlockAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IgnoreLoadingScreen;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AffectedByVisibleOption;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DebugClearAllow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool SkipInNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool ConditionFailPass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AchievementAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExecuteType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Time;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Delay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FinishType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Arg3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AffectedByVisibleFailReplaceGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBAchievementTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBAchievementTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CategoryType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool CheckParamOr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OpType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OpType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OpType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamType4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParamValue4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OpType4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CompleteValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CheckAchievementAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CompleteUIRequestGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> CompleteAcquisitionSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RewardAcquisitionSkillArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CompleteIncreaseMultiMapLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProgressAchievementOnCompleted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ProgressAchievementValueOnCompleted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProgressAchievementOnCompleted2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ProgressAchievementValueOnCompleted2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ProgressAchievementArrayOnCompleted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ProgressAchievementArrayValueOnCompleted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bMaintainNewGamePlus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
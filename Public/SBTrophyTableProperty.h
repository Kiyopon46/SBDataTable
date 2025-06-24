#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBTrophyTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBTrophyTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrophyGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Hidden;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString grade;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ProgressAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CompleteValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayName_StringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayDescription_StringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayName_en_us;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayDescription_en_us;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayName_ko_kr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DisplayDescription_ko_kr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBActivityTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBActivityTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsRequiredForCompletion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartActivityAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndActivityAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LinkActivities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SubCategory;

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
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBKeyMappingTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBKeyMappingTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RecommendationStrength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MappingGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DuplicateDenyArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DuplicateAllowArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAllowCombinationKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DuplicateCombinationKeyAllowArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActionNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AxisNames;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScaleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlotName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SlotDesc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoviePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ImagePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ViewerCategoryTypes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ViewerPriority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
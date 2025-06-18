#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBPhotoModeImageTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBPhotoModeImageTableProperty : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> UIOperateArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString OptionStringKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ImagePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString EnableConditionGroup;

};
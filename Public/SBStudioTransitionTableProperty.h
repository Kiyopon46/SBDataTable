#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBStudioTransitionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBStudioTransitionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TransitionShowTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TransitionSequenceTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bFade;

};
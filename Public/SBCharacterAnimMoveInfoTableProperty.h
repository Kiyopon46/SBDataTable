#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterAnimMoveInfoTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterAnimMoveInfoTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MovingDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MovingDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationDelayDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RotationDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LinearInterpRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AnimPlayDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AnimBlendTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InputBlockDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LinearInterpLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bOverrideLinearInterpLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 RotationDirType;

};
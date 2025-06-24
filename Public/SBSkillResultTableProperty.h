#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSkillResultTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSkillResultTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfCommonEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetCommonEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetCommonEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfCommonShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetCommonShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetCommonMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetCommonMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfDownEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetDownEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetDownEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfDownShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetDownShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetDownMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetDownMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfGroggyEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetGroggyEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetGroggyEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfGroggyShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetGroggyShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetGroggyMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetGroggyMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfAirborneEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetAirborneEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetAirborneEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfAirborneShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetAirborneShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetAirborneMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetAirborneMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfAirEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetAirEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetAirEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfAirShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetAirShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetAirMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetAirMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfSwimmingEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetSwimmingEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetSwimmingEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfSwimmingShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetSwimmingShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetSwimmingMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetSwimmingMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfCriticalEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetCriticalEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfCriticalShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetCriticalShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfWeakpointHitEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetWeakpointHitEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfEventMovingEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetEventMovingEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetEventMovingEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultSelfEventMovingShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetEventMovingShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ResultTargetEventMovingMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HitLevelResultTargetEventMovingMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
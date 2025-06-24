#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterAppearanceTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterAppearanceTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CapsuleRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CapsuleHalfHeight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BodyMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FaceMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BodyAnimAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FaceAnimAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FaceAttachType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BattleToPeacefulShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulToBattleShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulToBattleShowPath_LockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BattleToPeacefulShowPath_Move;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulToBattleShowPath_Move;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulToBattleShowPath_Move_LockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BattleToPeacefulShowPath_NoneAnim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulToBattleShowPath_NoneAnim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PeacefulToBattleShowPath_NoneAnim_LockOn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleToGroggyShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleToDownShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleToDeadShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IdleToAirborneShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DownToIdleShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroggyToIdleShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AirborneToIdleShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroggyToAirborneShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DownToAirborneShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroggyToDownShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AirborneToDownShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartSlopeShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndSlopeShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingAimToTakeBackShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingTakeBackToAimShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingTakeBackToCastingShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingCastingToWaitShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingWaitToFightShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingWaitToIdleShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingFightToIdleShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingCatchShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FishingLureChangeShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
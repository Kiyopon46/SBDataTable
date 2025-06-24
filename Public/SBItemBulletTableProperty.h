#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBItemBulletTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBItemBulletTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BulletAimImageType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> BulletStartEffectArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> BulletDroneStartEffectArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bTPSAimSlowDown;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TPS_TargetCheckCollisionRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TPS_ControllerYawDegree;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TPS_ControllerPitchDegree;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool TPS_EnableDamping;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TPS_DampingForce;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TPS_BulletMagnetismDegree;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAimLockOnTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AimLockOnTargetMaxCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AimLockOnTargetOverlapCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bHideWeakPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEquipmentTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEquipmentTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SubType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Tag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingResourcePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MaterialGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingResourceCollisionProfileName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnmountingResourcePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UnmountingEquipmentMassScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUnmountingEquipmentNoRemove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingEquipShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CompletedMountingEquipShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisableCompletedMountingEquipment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWorldStaticAndDynamicCollisionUnmounting;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bReleasablyMounted;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AnimAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FoldShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UnFoldShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ForceFoldShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UseSkillUnFoldShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartSlopeShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EndSlopeShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ChangeEquipmentShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CompleteChangeEquipmentShow;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttachSocket;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EditorAttachSocket;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RelativePosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RelativeRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttachType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveIdleAdditiveBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AdditiveBodyAlpha;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float IdleAdditiveAnimationMaxAlpha;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AttachRopeRelativeSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AttachRopeRelativeLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AdditionalComaReviveShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsEnableLowAngleEvent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterSoundSetOverride;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterFootstepSetOverride;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhotoModePoseSnapshotData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDisablePostProcessWhenPhotoModePoseSnapshot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhotoModePonytailSnapshotData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhotoModeHairSnapshotData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhotoModeTachyWingSnapshotData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SelfieModePoseSnapshotData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OverrideMaterialMeshSlot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OverrideMeshMaterialGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseHidePonytail;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString HideMeshSlot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLongHair;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingResourcePathWhenLongHair;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ForceBodyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MountingResourcePathWhenForceBodyType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
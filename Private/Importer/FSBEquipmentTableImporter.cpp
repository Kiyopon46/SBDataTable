#include "Importer/FSBEquipmentTableImporter.h"
#include "SBEquipmentTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEquipmentTableImporter"

FString FSBEquipmentTableImporter::GetDataTableName() const
{
    return "EquipmentTable";
}

TFunction<void()> FSBEquipmentTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEquipmentTableImporter::GetRowStruct() const
{
    return FSBEquipmentTableProperty::StaticStruct();
}

void FSBEquipmentTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
{
    // Get "Rows" Object
    const TSharedPtr<FJsonObject>* RowsObjectPtr = nullptr;
    if (!DataTableObject->TryGetObjectField(TEXT("Rows"), RowsObjectPtr) || !RowsObjectPtr) {
        UE_LOG(LogTemp, Error, TEXT("Rows field missing or invalid."));
        return;
    }

    const TSharedPtr<FJsonObject>& RowsObject = *RowsObjectPtr;
    for (const auto& RowPair : RowsObject->Values) {
        FString RowName = RowPair.Key;

        const TSharedPtr<FJsonObject>* RowDataObjectPtr;
        if (!RowPair.Value->TryGetObject(RowDataObjectPtr) || !RowDataObjectPtr) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid row object for RowName: %s"), *RowName);
            continue;
        }

        const TSharedPtr<FJsonObject>& RowDataObject = *RowDataObjectPtr;

        FSBEquipmentTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyStringField(RowDataObject, TEXT("SubType"), RowName, [&](const FString& Val) { NewRow.SubType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Tag"), RowName, [&](const FString& Val) { NewRow.Tag = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingResourcePath"), RowName, [&](const FString& Val) { NewRow.MountingResourcePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaterialGroup"), RowName, [&](const FString& Val) { NewRow.MaterialGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingResourceCollisionProfileName"), RowName, [&](const FString& Val) { NewRow.MountingResourceCollisionProfileName = Val; });
        TryApplyStringField(RowDataObject, TEXT("UnmountingResourcePath"), RowName, [&](const FString& Val) { NewRow.UnmountingResourcePath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UnmountingEquipmentMassScale"), RowName, [&](float Val) { NewRow.UnmountingEquipmentMassScale = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUnmountingEquipmentNoRemove"), RowName, [&](bool Val) { NewRow.bUnmountingEquipmentNoRemove = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingShowPath"), RowName, [&](const FString& Val) { NewRow.MountingShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingSocketName"), RowName, [&](const FString& Val) { NewRow.MountingSocketName = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingEquipShowPath"), RowName, [&](const FString& Val) { NewRow.MountingEquipShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("CompletedMountingEquipShowPath"), RowName, [&](const FString& Val) { NewRow.CompletedMountingEquipShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableCompletedMountingEquipment"), RowName, [&](bool Val) { NewRow.bDisableCompletedMountingEquipment = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWorldStaticAndDynamicCollisionUnmounting"), RowName, [&](bool Val) { NewRow.bWorldStaticAndDynamicCollisionUnmounting = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bReleasablyMounted"), RowName, [&](bool Val) { NewRow.bReleasablyMounted = Val; });
        TryApplyStringField(RowDataObject, TEXT("AnimAssetPath"), RowName, [&](const FString& Val) { NewRow.AnimAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FoldShow"), RowName, [&](const FString& Val) { NewRow.FoldShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("UnFoldShow"), RowName, [&](const FString& Val) { NewRow.UnFoldShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("ForceFoldShow"), RowName, [&](const FString& Val) { NewRow.ForceFoldShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("UseSkillUnFoldShow"), RowName, [&](const FString& Val) { NewRow.UseSkillUnFoldShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartSlopeShow"), RowName, [&](const FString& Val) { NewRow.StartSlopeShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndSlopeShow"), RowName, [&](const FString& Val) { NewRow.EndSlopeShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("ChangeEquipmentShow"), RowName, [&](const FString& Val) { NewRow.ChangeEquipmentShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("CompleteChangeEquipmentShow"), RowName, [&](const FString& Val) { NewRow.CompleteChangeEquipmentShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttachSocket"), RowName, [&](const FString& Val) { NewRow.AttachSocket = Val; });
        TryApplyStringField(RowDataObject, TEXT("EditorAttachSocket"), RowName, [&](const FString& Val) { NewRow.EditorAttachSocket = Val; });
        TryApplyStringField(RowDataObject, TEXT("RelativePosition"), RowName, [&](const FString& Val) { NewRow.RelativePosition = Val; });
        TryApplyStringField(RowDataObject, TEXT("RelativeRotation"), RowName, [&](const FString& Val) { NewRow.RelativeRotation = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttachType"), RowName, [&](const FString& Val) { NewRow.AttachType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveIdleAdditiveBody"), RowName, [&](const FString& Val) { NewRow.ActiveIdleAdditiveBody = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AdditiveBodyAlpha"), RowName, [&](float Val) { NewRow.AdditiveBodyAlpha = Val; });
        TryApplyFloatField(RowDataObject, TEXT("IdleAdditiveAnimationMaxAlpha"), RowName, [&](float Val) { NewRow.IdleAdditiveAnimationMaxAlpha = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AttachRopeRelativeSocketName"), RowName, [&](const TArray<FString>& Val) { NewRow.AttachRopeRelativeSocketName = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AttachRopeRelativeLocation"), RowName, [&](const TArray<FString>& Val) { NewRow.AttachRopeRelativeLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("AdditionalComaReviveShowPath"), RowName, [&](const FString& Val) { NewRow.AdditionalComaReviveShowPath = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IsEnableLowAngleEvent"), RowName, [&](bool Val) { NewRow.IsEnableLowAngleEvent = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterSoundSetOverride"), RowName, [&](const FString& Val) { NewRow.CharacterSoundSetOverride = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterFootstepSetOverride"), RowName, [&](const FString& Val) { NewRow.CharacterFootstepSetOverride = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhotoModePoseSnapshotData"), RowName, [&](const FString& Val) { NewRow.PhotoModePoseSnapshotData = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisablePostProcessWhenPhotoModePoseSnapshot"), RowName, [&](bool Val) { NewRow.bDisablePostProcessWhenPhotoModePoseSnapshot = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhotoModePonytailSnapshotData"), RowName, [&](const FString& Val) { NewRow.PhotoModePonytailSnapshotData = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhotoModeHairSnapshotData"), RowName, [&](const FString& Val) { NewRow.PhotoModeHairSnapshotData = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhotoModeTachyWingSnapshotData"), RowName, [&](const FString& Val) { NewRow.PhotoModeTachyWingSnapshotData = Val; });
        TryApplyStringField(RowDataObject, TEXT("SelfieModePoseSnapshotData"), RowName, [&](const FString& Val) { NewRow.SelfieModePoseSnapshotData = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideMaterialMeshSlot"), RowName, [&](const FString& Val) { NewRow.OverrideMaterialMeshSlot = Val; });
        TryApplyStringField(RowDataObject, TEXT("OverrideMeshMaterialGroup"), RowName, [&](const FString& Val) { NewRow.OverrideMeshMaterialGroup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseHidePonytail"), RowName, [&](bool Val) { NewRow.bUseHidePonytail = Val; });
        TryApplyStringField(RowDataObject, TEXT("HideMeshSlot"), RowName, [&](const FString& Val) { NewRow.HideMeshSlot = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLongHair"), RowName, [&](bool Val) { NewRow.bLongHair = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingResourcePathWhenLongHair"), RowName, [&](const FString& Val) { NewRow.MountingResourcePathWhenLongHair = Val; });
        TryApplyStringField(RowDataObject, TEXT("ForceBodyType"), RowName, [&](const FString& Val) { NewRow.ForceBodyType = Val; });
        TryApplyStringField(RowDataObject, TEXT("MountingResourcePathWhenForceBodyType1"), RowName, [&](const FString& Val) { NewRow.MountingResourcePathWhenForceBodyType1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

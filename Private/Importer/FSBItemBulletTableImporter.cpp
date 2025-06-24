#include "Importer/FSBItemBulletTableImporter.h"
#include "SBItemBulletTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemBulletTableImporter"

FString FSBItemBulletTableImporter::GetDataTableName() const
{
    return "ItemBulletTable";
}

TFunction<void()> FSBItemBulletTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemBulletTableImporter::GetRowStruct() const
{
    return FSBItemBulletTableProperty::StaticStruct();
}

void FSBItemBulletTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemBulletTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("BulletAimImageType"), RowName, [&](const FString& Val) { NewRow.BulletAimImageType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("BulletStartEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.BulletStartEffectArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("BulletDroneStartEffectArray"), RowName, [&](const TArray<FString>& Val) { NewRow.BulletDroneStartEffectArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bTPSAimSlowDown"), RowName, [&](bool Val) { NewRow.bTPSAimSlowDown = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TPS_TargetCheckCollisionRadius"), RowName, [&](float Val) { NewRow.TPS_TargetCheckCollisionRadius = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TPS_ControllerYawDegree"), RowName, [&](float Val) { NewRow.TPS_ControllerYawDegree = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TPS_ControllerPitchDegree"), RowName, [&](float Val) { NewRow.TPS_ControllerPitchDegree = Val; });
        TryApplyBoolField(RowDataObject, TEXT("TPS_EnableDamping"), RowName, [&](bool Val) { NewRow.TPS_EnableDamping = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TPS_DampingForce"), RowName, [&](float Val) { NewRow.TPS_DampingForce = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TPS_BulletMagnetismDegree"), RowName, [&](float Val) { NewRow.TPS_BulletMagnetismDegree = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAimLockOnTarget"), RowName, [&](bool Val) { NewRow.bAimLockOnTarget = Val; });
        TryApplyIntField(RowDataObject, TEXT("AimLockOnTargetMaxCount"), RowName, [&](int32 Val) { NewRow.AimLockOnTargetMaxCount = Val; });
        TryApplyIntField(RowDataObject, TEXT("AimLockOnTargetOverlapCount"), RowName, [&](int32 Val) { NewRow.AimLockOnTargetOverlapCount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bHideWeakPoint"), RowName, [&](bool Val) { NewRow.bHideWeakPoint = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

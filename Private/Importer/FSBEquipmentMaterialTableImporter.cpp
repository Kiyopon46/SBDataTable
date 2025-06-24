#include "Importer/FSBEquipmentMaterialTableImporter.h"
#include "SBEquipmentMaterialTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEquipmentMaterialTableImporter"

FString FSBEquipmentMaterialTableImporter::GetDataTableName() const
{
    return "EquipmentMaterialTable";
}

TFunction<void()> FSBEquipmentMaterialTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEquipmentMaterialTableImporter::GetRowStruct() const
{
    return FSBEquipmentMaterialTableProperty::StaticStruct();
}

void FSBEquipmentMaterialTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEquipmentMaterialTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Group"), RowName, [&](const FString& Val) { NewRow.Group = Val; });
        TryApplyIntField(RowDataObject, TEXT("VariationIndex"), RowName, [&](int32 Val) { NewRow.VariationIndex = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaterialIndex"), RowName, [&](int32 Val) { NewRow.MaterialIndex = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaterialAssetPath"), RowName, [&](const FString& Val) { NewRow.MaterialAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("IconColorAssetPath"), RowName, [&](const FString& Val) { NewRow.IconColorAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

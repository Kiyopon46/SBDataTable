#include "Importer/FSBItemSkillEquipableTableImporter.h"
#include "SBItemSkillEquipableTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemSkillEquipableTableImporter"

FString FSBItemSkillEquipableTableImporter::GetDataTableName() const
{
    return "ItemSkillEquipableTable";
}

TFunction<void()> FSBItemSkillEquipableTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemSkillEquipableTableImporter::GetRowStruct() const
{
    return FSBItemSkillEquipableTableProperty::StaticStruct();
}

void FSBItemSkillEquipableTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemSkillEquipableTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("ItemSkillEquipableAlias"), RowName, [&](const FString& Val) { NewRow.ItemSkillEquipableAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("Level"), RowName, [&](int32 Val) { NewRow.Level = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AcquisitionSkillAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.AcquisitionSkillAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillCommandAlias"), RowName, [&](const FString& Val) { NewRow.SkillCommandAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EquipEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EquipEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UnequipEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UnequipEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RequiredItemAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.RequiredItemAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RequiredItemAmountArray"), RowName, [&](const TArray<FString>& Val) { NewRow.RequiredItemAmountArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

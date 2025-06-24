#include "Importer/FSBItemEquipableTableImporter.h"
#include "SBItemEquipableTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemEquipableTableImporter"

FString FSBItemEquipableTableImporter::GetDataTableName() const
{
    return "ItemEquipableTable";
}

TFunction<void()> FSBItemEquipableTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemEquipableTableImporter::GetRowStruct() const
{
    return FSBItemEquipableTableProperty::StaticStruct();
}

void FSBItemEquipableTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemEquipableTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("GearType"), RowName, [&](const FString& Val) { NewRow.GearType = Val; });
        TryApplyStringField(RowDataObject, TEXT("BaseStatGroupAlias"), RowName, [&](const FString& Val) { NewRow.BaseStatGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

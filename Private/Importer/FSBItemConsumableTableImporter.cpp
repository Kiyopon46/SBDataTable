#include "Importer/FSBItemConsumableTableImporter.h"
#include "SBItemConsumableTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemConsumableTableImporter"

FString FSBItemConsumableTableImporter::GetDataTableName() const
{
    return "ItemConsumableTable";
}

TFunction<void()> FSBItemConsumableTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemConsumableTableImporter::GetRowStruct() const
{
    return FSBItemConsumableTableProperty::StaticStruct();
}

void FSBItemConsumableTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemConsumableTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("ConsumeImmidiate"), RowName, [&](bool Val) { NewRow.ConsumeImmidiate = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConsumeCoolTime"), RowName, [&](int32 Val) { NewRow.ConsumeCoolTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConsumeSkillAlias"), RowName, [&](const FString& Val) { NewRow.ConsumeSkillAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConsumeEnergyType"), RowName, [&](const FString& Val) { NewRow.ConsumeEnergyType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ConsumeEnergyAmount"), RowName, [&](float Val) { NewRow.ConsumeEnergyAmount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("NotRemoveItem"), RowName, [&](bool Val) { NewRow.NotRemoveItem = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

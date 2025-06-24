#include "Importer/FSBItemReplacementTableImporter.h"
#include "SBItemReplacementTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemReplacementTableImporter"

FString FSBItemReplacementTableImporter::GetDataTableName() const
{
    return "ItemReplacementTable";
}

TFunction<void()> FSBItemReplacementTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemReplacementTableImporter::GetRowStruct() const
{
    return FSBItemReplacementTableProperty::StaticStruct();
}

void FSBItemReplacementTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemReplacementTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReplacementItemAlias"), RowName, [&](const FString& Val) { NewRow.ReplacementItemAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("ReplacementItemAmount"), RowName, [&](int32 Val) { NewRow.ReplacementItemAmount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("UseRewardDirectOverride"), RowName, [&](bool Val) { NewRow.UseRewardDirectOverride = Val; });
        TryApplyBoolField(RowDataObject, TEXT("RewardDirectValue"), RowName, [&](bool Val) { NewRow.RewardDirectValue = Val; });
        TryApplyBoolField(RowDataObject, TEXT("UseRewardMustAcquisitionOverride"), RowName, [&](bool Val) { NewRow.UseRewardMustAcquisitionOverride = Val; });
        TryApplyBoolField(RowDataObject, TEXT("RewardMustAcquisition"), RowName, [&](bool Val) { NewRow.RewardMustAcquisition = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

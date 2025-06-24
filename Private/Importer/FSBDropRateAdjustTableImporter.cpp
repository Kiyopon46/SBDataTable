#include "Importer/FSBDropRateAdjustTableImporter.h"
#include "SBDropRateAdjustTableTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBDropRateAdjustTableImporter"

FString FSBDropRateAdjustTableImporter::GetDataTableName() const
{
    return "DropRateAdjustTable";
}

TFunction<void()> FSBDropRateAdjustTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBDropRateAdjustTableImporter::GetRowStruct() const
{
    return FSBDropRateAdjustTableTableProperty::StaticStruct();
}

void FSBDropRateAdjustTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBDropRateAdjustTableTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("RarityCommon"), RowName, [&](int32 Val) { NewRow.RarityCommon = Val; });
        TryApplyIntField(RowDataObject, TEXT("RarityUncommon"), RowName, [&](int32 Val) { NewRow.RarityUncommon = Val; });
        TryApplyIntField(RowDataObject, TEXT("RarityRare"), RowName, [&](int32 Val) { NewRow.RarityRare = Val; });
        TryApplyIntField(RowDataObject, TEXT("RarityEpic"), RowName, [&](int32 Val) { NewRow.RarityEpic = Val; });
        TryApplyIntField(RowDataObject, TEXT("RarityLegendary"), RowName, [&](int32 Val) { NewRow.RarityLegendary = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

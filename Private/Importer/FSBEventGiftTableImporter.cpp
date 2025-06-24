#include "Importer/FSBEventGiftTableImporter.h"
#include "SBEventGiftTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventGiftTableImporter"

FString FSBEventGiftTableImporter::GetDataTableName() const
{
    return "EventGiftTable";
}

TFunction<void()> FSBEventGiftTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventGiftTableImporter::GetRowStruct() const
{
    return FSBEventGiftTableProperty::StaticStruct();
}

void FSBEventGiftTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventGiftTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("GiftType"), RowName, [&](const FString& Val) { NewRow.GiftType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ItemList"), RowName, [&](const TArray<FString>& Val) { NewRow.ItemList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ItemAmountList"), RowName, [&](const TArray<FString>& Val) { NewRow.ItemAmountList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ItemLevelList"), RowName, [&](const TArray<FString>& Val) { NewRow.ItemLevelList = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBItemLureTableImporter.h"
#include "SBItemLureTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemLureTableImporter"

FString FSBItemLureTableImporter::GetDataTableName() const
{
    return "ItemLureTable";
}

TFunction<void()> FSBItemLureTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemLureTableImporter::GetRowStruct() const
{
    return FSBItemLureTableProperty::StaticStruct();
}

void FSBItemLureTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemLureTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory1"), RowName, [&](const FString& Val) { NewRow.FishCategory1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd1"), RowName, [&](int32 Val) { NewRow.BiteRateAdd1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory2"), RowName, [&](const FString& Val) { NewRow.FishCategory2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd2"), RowName, [&](int32 Val) { NewRow.BiteRateAdd2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory3"), RowName, [&](const FString& Val) { NewRow.FishCategory3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd3"), RowName, [&](int32 Val) { NewRow.BiteRateAdd3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory4"), RowName, [&](const FString& Val) { NewRow.FishCategory4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd4"), RowName, [&](int32 Val) { NewRow.BiteRateAdd4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory5"), RowName, [&](const FString& Val) { NewRow.FishCategory5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd5"), RowName, [&](int32 Val) { NewRow.BiteRateAdd5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory6"), RowName, [&](const FString& Val) { NewRow.FishCategory6 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd6"), RowName, [&](int32 Val) { NewRow.BiteRateAdd6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory7"), RowName, [&](const FString& Val) { NewRow.FishCategory7 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd7"), RowName, [&](int32 Val) { NewRow.BiteRateAdd7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory8"), RowName, [&](const FString& Val) { NewRow.FishCategory8 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd8"), RowName, [&](int32 Val) { NewRow.BiteRateAdd8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory9"), RowName, [&](const FString& Val) { NewRow.FishCategory9 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd9"), RowName, [&](int32 Val) { NewRow.BiteRateAdd9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory10"), RowName, [&](const FString& Val) { NewRow.FishCategory10 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd10"), RowName, [&](int32 Val) { NewRow.BiteRateAdd10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory11"), RowName, [&](const FString& Val) { NewRow.FishCategory11 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd11"), RowName, [&](int32 Val) { NewRow.BiteRateAdd11 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishCategory12"), RowName, [&](const FString& Val) { NewRow.FishCategory12 = Val; });
        TryApplyIntField(RowDataObject, TEXT("BiteRateAdd12"), RowName, [&](int32 Val) { NewRow.BiteRateAdd12 = Val; });
        TryApplyStringField(RowDataObject, TEXT("WeightUp"), RowName, [&](const FString& Val) { NewRow.WeightUp = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

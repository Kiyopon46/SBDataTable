#include "Importer/FSBHintTableImporter.h"
#include "SBHintTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBHintTableImporter"

FString FSBHintTableImporter::GetDataTableName() const
{
    return "HintTable";
}

TFunction<void()> FSBHintTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBHintTableImporter::GetRowStruct() const
{
    return FSBHintTableProperty::StaticStruct();
}

void FSBHintTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBHintTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("DelayActivateTimeSec"), RowName, [&](int32 Val) { NewRow.DelayActivateTimeSec = Val; });
        TryApplyIntField(RowDataObject, TEXT("LongTimeDelayActivateTimeSec"), RowName, [&](int32 Val) { NewRow.LongTimeDelayActivateTimeSec = Val; });
        TryApplyStringField(RowDataObject, TEXT("HintMessage_StringKey"), RowName, [&](const FString& Val) { NewRow.HintMessage_StringKey = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActivateZoneTriggerAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ActivateZoneTriggerAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

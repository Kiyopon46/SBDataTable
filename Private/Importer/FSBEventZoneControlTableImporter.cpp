#include "Importer/FSBEventZoneControlTableImporter.h"
#include "SBZoneEventZoneControlTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventZoneControlTableImporter"

FString FSBEventZoneControlTableImporter::GetDataTableName() const
{
    return "EventZoneControlTable";
}

TFunction<void()> FSBEventZoneControlTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventZoneControlTableImporter::GetRowStruct() const
{
    return FSBZoneEventZoneControlTableProperty::StaticStruct();
}

void FSBEventZoneControlTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventZoneControlTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneAlias"), RowName, [&](const FString& Val) { NewRow.ZoneAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ControlType"), RowName, [&](const FString& Val) { NewRow.ControlType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

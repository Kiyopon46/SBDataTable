#include "Importer/FSBZoneEventTableImporter.h"
#include "SBZoneEventTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneEventTableImporter"

FString FSBZoneEventTableImporter::GetDataTableName() const
{
    return "ZoneEventTable";
}

TFunction<void()> FSBZoneEventTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneEventTableImporter::GetRowStruct() const
{
    return FSBZoneEventTableProperty::StaticStruct();
}

void FSBZoneEventTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventAlias"), RowName, [&](const FString& Val) { NewRow.EventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionCheckType"), RowName, [&](const FString& Val) { NewRow.EventConditionCheckType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EventDelayTime"), RowName, [&](float Val) { NewRow.EventDelayTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EventDelayMinTime"), RowName, [&](float Val) { NewRow.EventDelayMinTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EventDelayMaxTime"), RowName, [&](float Val) { NewRow.EventDelayMaxTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IgnoreEventByPlayerDead"), RowName, [&](bool Val) { NewRow.IgnoreEventByPlayerDead = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FinishEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.FinishEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AddEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.AddEvents = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

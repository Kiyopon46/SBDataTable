#include "Importer/FSBZonePhaseEventTableImporter.h"
#include "SBZonePhaseEventTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZonePhaseEventTableImporter"

FString FSBZonePhaseEventTableImporter::GetDataTableName() const
{
    return "ZonePhaseEventTable";
}

TFunction<void()> FSBZonePhaseEventTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZonePhaseEventTableImporter::GetRowStruct() const
{
    return FSBZonePhaseEventTableProperty::StaticStruct();
}

void FSBZonePhaseEventTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZonePhaseEventTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhaseEventType"), RowName, [&](const FString& Val) { NewRow.PhaseEventType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveEventType"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveEventType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StartEventType"), RowName, [&](const TArray<FString>& Val) { NewRow.StartEventType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StartEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.StartEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteEventType"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteEventType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveZoneEventList"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveZoneEventList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("StartZoneEventList"), RowName, [&](const TArray<FString>& Val) { NewRow.StartZoneEventList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteZoneEventList"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteZoneEventList = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhaseEventCompleteType"), RowName, [&](const FString& Val) { NewRow.PhaseEventCompleteType = Val; });
        TryApplyIntField(RowDataObject, TEXT("PhaseEventCompleteValue"), RowName, [&](int32 Val) { NewRow.PhaseEventCompleteValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextPhaseEvent"), RowName, [&](const FString& Val) { NewRow.NextPhaseEvent = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PhaseEventDelayTime"), RowName, [&](float Val) { NewRow.PhaseEventDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWithDestory"), RowName, [&](bool Val) { NewRow.bWithDestory = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

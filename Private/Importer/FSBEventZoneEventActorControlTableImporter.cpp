#include "Importer/FSBEventZoneEventActorControlTableImporter.h"
#include "SBEventZoneEventActorControlTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventZoneEventActorControlTableImporter"

FString FSBEventZoneEventActorControlTableImporter::GetDataTableName() const
{
    return "EventZoneEventActorControlTable";
}

TFunction<void()> FSBEventZoneEventActorControlTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventZoneEventActorControlTableImporter::GetRowStruct() const
{
    return FSBEventZoneEventActorControlTableProperty::StaticStruct();
}

void FSBEventZoneEventActorControlTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventZoneEventActorControlTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneEventActorName"), RowName, [&](const FString& Val) { NewRow.ZoneEventActorName = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneEventActorControlType"), RowName, [&](const FString& Val) { NewRow.ZoneEventActorControlType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DestructionTime"), RowName, [&](float Val) { NewRow.DestructionTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableDestruction"), RowName, [&](bool Val) { NewRow.bDisableDestruction = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

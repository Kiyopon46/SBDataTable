#include "Importer/FSBEventMetaAITableImporter.h"
#include "SBEventMetaAITableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventMetaAITableImporter"

FString FSBEventMetaAITableImporter::GetDataTableName() const
{
    return "EventMetaAITable";
}

TFunction<void()> FSBEventMetaAITableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventMetaAITableImporter::GetRowStruct() const
{
    return FSBEventMetaAITableProperty::StaticStruct();
}

void FSBEventMetaAITableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventMetaAITableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ToTarget"), RowName, [&](const FString& Val) { NewRow.ToTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTagName"), RowName, [&](const FString& Val) { NewRow.TargetTagName = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("MetaAIEventType"), RowName, [&](const FString& Val) { NewRow.MetaAIEventType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpecialBehaviorTag"), RowName, [&](const FString& Val) { NewRow.SpecialBehaviorTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("AddTag"), RowName, [&](const FString& Val) { NewRow.AddTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("ForceThink"), RowName, [&](const FString& Val) { NewRow.ForceThink = Val; });
        TryApplyStringField(RowDataObject, TEXT("ForceThink_BehaviorAlias"), RowName, [&](const FString& Val) { NewRow.ForceThink_BehaviorAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

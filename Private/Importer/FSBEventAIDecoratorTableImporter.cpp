#include "Importer/FSBEventAIDecoratorTableImporter.h"
#include "SBZoneEventAIDecoTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventAIDecoratorTableImporter"

FString FSBEventAIDecoratorTableImporter::GetDataTableName() const
{
    return "EventAIDecoratorTable";
}

TFunction<void()> FSBEventAIDecoratorTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventAIDecoratorTableImporter::GetRowStruct() const
{
    return FSBZoneEventAIDecoTableProperty::StaticStruct();
}

void FSBEventAIDecoratorTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventAIDecoTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetFilter"), RowName, [&](const FString& Val) { NewRow.TargetFilter = Val; });
        TryApplyStringField(RowDataObject, TEXT("ValueKey"), RowName, [&](const FString& Val) { NewRow.ValueKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ValueType"), RowName, [&](const FString& Val) { NewRow.ValueType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CustomValue1"), RowName, [&](float Val) { NewRow.CustomValue1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CustomValue2"), RowName, [&](float Val) { NewRow.CustomValue2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CustomValue3"), RowName, [&](float Val) { NewRow.CustomValue3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

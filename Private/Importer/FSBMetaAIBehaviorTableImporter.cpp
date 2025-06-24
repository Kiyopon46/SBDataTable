#include "Importer/FSBMetaAIBehaviorTableImporter.h"
#include "SBMetaAIBehaviorTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBMetaAIBehaviorTableImporter"

FString FSBMetaAIBehaviorTableImporter::GetDataTableName() const
{
    return "MetaAIBehaviorTable";
}

TFunction<void()> FSBMetaAIBehaviorTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBMetaAIBehaviorTableImporter::GetRowStruct() const
{
    return FSBMetaAIBehaviorTableProperty::StaticStruct();
}

void FSBMetaAIBehaviorTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBMetaAIBehaviorTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FindDistance"), RowName, [&](float Val) { NewRow.FindDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Interval"), RowName, [&](float Val) { NewRow.Interval = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AcitiveProbability"), RowName, [&](float Val) { NewRow.AcitiveProbability = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TirednessPerSecond"), RowName, [&](float Val) { NewRow.TirednessPerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Condition_StartTiredness"), RowName, [&](float Val) { NewRow.Condition_StartTiredness = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_StartTiredness_OperationType"), RowName, [&](const FString& Val) { NewRow.Condition_StartTiredness_OperationType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Condition_EndTiredness"), RowName, [&](float Val) { NewRow.Condition_EndTiredness = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition_EndTiredness_OperationType"), RowName, [&](const FString& Val) { NewRow.Condition_EndTiredness_OperationType = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

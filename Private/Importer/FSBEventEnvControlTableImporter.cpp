#include "Importer/FSBEventEnvControlTableImporter.h"
#include "SBEventEnvControlTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventEnvControlTableImporter"

FString FSBEventEnvControlTableImporter::GetDataTableName() const
{
    return "EventEnvControlTable";
}

TFunction<void()> FSBEventEnvControlTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventEnvControlTableImporter::GetRowStruct() const
{
    return FSBEventEnvControlTableProperty::StaticStruct();
}

void FSBEventEnvControlTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventEnvControlTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvSpawnAlias"), RowName, [&](const FString& Val) { NewRow.EnvSpawnAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvControlType"), RowName, [&](const FString& Val) { NewRow.EnvControlType = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetCamp"), RowName, [&](const FString& Val) { NewRow.TargetCamp = Val; });
        TryApplyStringField(RowDataObject, TEXT("TagName"), RowName, [&](const FString& Val) { NewRow.TagName = Val; });
        TryApplyStringField(RowDataObject, TEXT("Activate"), RowName, [&](const FString& Val) { NewRow.Activate = Val; });
        TryApplyIntField(RowDataObject, TEXT("AddProgressValue"), RowName, [&](int32 Val) { NewRow.AddProgressValue = Val; });
        TryApplyIntField(RowDataObject, TEXT("SetStateProgressValue"), RowName, [&](int32 Val) { NewRow.SetStateProgressValue = Val; });
        TryApplyIntField(RowDataObject, TEXT("ProgressSlotIndex"), RowName, [&](int32 Val) { NewRow.ProgressSlotIndex = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ProgressSpeed"), RowName, [&](float Val) { NewRow.ProgressSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ProgressSpeedInterpTime"), RowName, [&](float Val) { NewRow.ProgressSpeedInterpTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CurrentProgressValue"), RowName, [&](float Val) { NewRow.CurrentProgressValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartProgressValue"), RowName, [&](float Val) { NewRow.StartProgressValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EndProgressValue"), RowName, [&](float Val) { NewRow.EndProgressValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

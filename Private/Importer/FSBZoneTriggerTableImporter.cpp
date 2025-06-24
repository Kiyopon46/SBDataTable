#include "Importer/FSBZoneTriggerTableImporter.h"
#include "SBZoneTriggerTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneTriggerTableImporter"

FString FSBZoneTriggerTableImporter::GetDataTableName() const
{
    return "ZoneTriggerTable";
}

TFunction<void()> FSBZoneTriggerTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneTriggerTableImporter::GetRowStruct() const
{
    return FSBZoneTriggerTableProperty::StaticStruct();
}

void FSBZoneTriggerTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneTriggerTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Zone"), RowName, [&](const FString& Val) { NewRow.Zone = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitActivate"), RowName, [&](const FString& Val) { NewRow.InitActivate = Val; });
        TryApplyStringField(RowDataObject, TEXT("TriggerType"), RowName, [&](const FString& Val) { NewRow.TriggerType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TouchEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.TouchEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LeaveEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.LeaveEvents = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition"), RowName, [&](const FString& Val) { NewRow.Condition = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("TriggerActorAlias"), RowName, [&](const FString& Val) { NewRow.TriggerActorAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoingType"), RowName, [&](const FString& Val) { NewRow.DoingType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("InOutTrigger"), RowName, [&](bool Val) { NewRow.InOutTrigger = Val; });
        TryApplyIntField(RowDataObject, TEXT("InitialDoingCount"), RowName, [&](int32 Val) { NewRow.InitialDoingCount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IgnoreDoingCount"), RowName, [&](bool Val) { NewRow.IgnoreDoingCount = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActiveRange"), RowName, [&](float Val) { NewRow.ActiveRange = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("BoxExtent"), RowName, [&](const FString& Val) { NewRow.BoxExtent = Val; });
        TryApplyStringField(RowDataObject, TEXT("IgnoreFilter"), RowName, [&](const FString& Val) { NewRow.IgnoreFilter = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionObjectMaterial"), RowName, [&](const FString& Val) { NewRow.ConditionObjectMaterial = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelTargetFilter"), RowName, [&](const FString& Val) { NewRow.LevelTargetFilter = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BlockExtraSprintDuration"), RowName, [&](float Val) { NewRow.BlockExtraSprintDuration = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

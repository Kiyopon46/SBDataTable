#include "Importer/FSBEventObjectControlTableImporter.h"
#include "SBZoneEventObjControl.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventObjectControlTableImporter"

FString FSBEventObjectControlTableImporter::GetDataTableName() const
{
    return "EventObjectControlTable";
}

TFunction<void()> FSBEventObjectControlTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventObjectControlTableImporter::GetRowStruct() const
{
    return FSBZoneEventObjControl::StaticStruct();
}

void FSBEventObjectControlTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventObjControl NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetDataAlias"), RowName, [&](const FString& Val) { NewRow.TargetDataAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetFilter"), RowName, [&](const FString& Val) { NewRow.TargetFilter = Val; });
        TryApplyStringField(RowDataObject, TEXT("ObjectType"), RowName, [&](const FString& Val) { NewRow.ObjectType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Activate"), RowName, [&](const FString& Val) { NewRow.Activate = Val; });
        TryApplyStringField(RowDataObject, TEXT("ObjectControlActionType"), RowName, [&](const FString& Val) { NewRow.ObjectControlActionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RetargetSpawnPointName"), RowName, [&](const FString& Val) { NewRow.RetargetSpawnPointName = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bWithStorage"), RowName, [&](bool Val) { NewRow.bWithStorage = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

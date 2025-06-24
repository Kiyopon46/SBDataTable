#include "Importer/FSBEventInteractCampTableImporter.h"
#include "SBEventInteractCampTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventInteractCampTableImporter"

FString FSBEventInteractCampTableImporter::GetDataTableName() const
{
    return "EventInteractCampTable";
}

TFunction<void()> FSBEventInteractCampTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventInteractCampTableImporter::GetRowStruct() const
{
    return FSBEventInteractCampTableProperty::StaticStruct();
}

void FSBEventInteractCampTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventInteractCampTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampEnvSpawnAlias"), RowName, [&](const FString& Val) { NewRow.CampEnvSpawnAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractType"), RowName, [&](const FString& Val) { NewRow.InteractType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bShowResetZoneUI"), RowName, [&](bool Val) { NewRow.bShowResetZoneUI = Val; });
        TryApplyStringField(RowDataObject, TEXT("DoingSaveType"), RowName, [&](const FString& Val) { NewRow.DoingSaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SoundEventAlias"), RowName, [&](const FString& Val) { NewRow.SoundEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBWorldTransitionTableImporter.h"
#include "SBWorldTransitionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBWorldTransitionTableImporter"

FString FSBWorldTransitionTableImporter::GetDataTableName() const
{
    return "WorldTransitionTable";
}

TFunction<void()> FSBWorldTransitionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBWorldTransitionTableImporter::GetRowStruct() const
{
    return FSBWorldTransitionTableProperty::StaticStruct();
}

void FSBWorldTransitionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBWorldTransitionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TransitionType"), RowName, [&](const FString& Val) { NewRow.TransitionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnableConditionGroup"), RowName, [&](const FString& Val) { NewRow.EnableConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("TriggerAlias"), RowName, [&](const FString& Val) { NewRow.TriggerAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.ZoneEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvSpawnAlias"), RowName, [&](const FString& Val) { NewRow.EnvSpawnAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EventSpawnAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EventSpawnAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("FromWorldAlias"), RowName, [&](const FString& Val) { NewRow.FromWorldAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FromIsolatedAreaAlias"), RowName, [&](const FString& Val) { NewRow.FromIsolatedAreaAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ToWorldAlias"), RowName, [&](const FString& Val) { NewRow.ToWorldAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ToIsolatedAreaAlias"), RowName, [&](const FString& Val) { NewRow.ToIsolatedAreaAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ToDescStringKey"), RowName, [&](const FString& Val) { NewRow.ToDescStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("PortalTag"), RowName, [&](const FString& Val) { NewRow.PortalTag = Val; });
        TryApplyBoolField(RowDataObject, TEXT("EnableWorldMapPortal"), RowName, [&](bool Val) { NewRow.EnableWorldMapPortal = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

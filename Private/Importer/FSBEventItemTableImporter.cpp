#include "Importer/FSBEventItemTableImporter.h"
#include "SBZoneEventItemTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventItemTableImporter"

FString FSBEventItemTableImporter::GetDataTableName() const
{
    return "EventItemTable";
}

TFunction<void()> FSBEventItemTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventItemTableImporter::GetRowStruct() const
{
    return FSBZoneEventItemTableProperty::StaticStruct();
}

void FSBEventItemTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventItemTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ControlType"), RowName, [&](const FString& Val) { NewRow.ControlType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnType"), RowName, [&](const FString& Val) { NewRow.SpawnType = Val; });
        TryApplyStringField(RowDataObject, TEXT("World"), RowName, [&](const FString& Val) { NewRow.World = Val; });
        TryApplyStringField(RowDataObject, TEXT("Zone"), RowName, [&](const FString& Val) { NewRow.Zone = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventorType"), RowName, [&](const FString& Val) { NewRow.EventorType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnPointName"), RowName, [&](const FString& Val) { NewRow.SpawnPointName = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnItemAlias"), RowName, [&](const FString& Val) { NewRow.SpawnItemAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("SpawnItemCount"), RowName, [&](int32 Val) { NewRow.SpawnItemCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnInfoAlias"), RowName, [&](const FString& Val) { NewRow.SpawnInfoAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnItemBucketType"), RowName, [&](const FString& Val) { NewRow.SpawnItemBucketType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EventDelayTime"), RowName, [&](float Val) { NewRow.EventDelayTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckAchievements"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckAchievements = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AcquireZoneEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.AcquireZoneEvents = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseOverrideAutoInteraction"), RowName, [&](bool Val) { NewRow.bUseOverrideAutoInteraction = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAutoInteraction"), RowName, [&](bool Val) { NewRow.bAutoInteraction = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AutoInteractionDist"), RowName, [&](float Val) { NewRow.AutoInteractionDist = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

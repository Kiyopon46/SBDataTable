#include "Importer/FSBQuestMissionTableImporter.h"
#include "SBQuestMissionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBQuestMissionTableImporter"

FString FSBQuestMissionTableImporter::GetDataTableName() const
{
    return "QuestMissionTable";
}

TFunction<void()> FSBQuestMissionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBQuestMissionTableImporter::GetRowStruct() const
{
    return FSBQuestMissionTableProperty::StaticStruct();
}

void FSBQuestMissionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBQuestMissionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("MissionType"), RowName, [&](const FString& Val) { NewRow.MissionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("OwnerFilter"), RowName, [&](const FString& Val) { NewRow.OwnerFilter = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetFilter"), RowName, [&](const FString& Val) { NewRow.TargetFilter = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStr"), RowName, [&](const FString& Val) { NewRow.CustomStr = Val; });
        TryApplyIntField(RowDataObject, TEXT("CustomValue"), RowName, [&](int32 Val) { NewRow.CustomValue = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConditionCount"), RowName, [&](int32 Val) { NewRow.ConditionCount = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Radius"), RowName, [&](float Val) { NewRow.Radius = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActivateEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.ActivateEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProgressEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.ProgressEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteEvent = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

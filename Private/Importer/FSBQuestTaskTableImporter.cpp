#include "Importer/FSBQuestTaskTableImporter.h"
#include "SBQuestTaskTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBQuestTaskTableImporter"

FString FSBQuestTaskTableImporter::GetDataTableName() const
{
    return "QuestTaskTable";
}

TFunction<void()> FSBQuestTaskTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBQuestTaskTableImporter::GetRowStruct() const
{
    return FSBQuestTaskTableProperty::StaticStruct();
}

void FSBQuestTaskTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBQuestTaskTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description"), RowName, [&](const FString& Val) { NewRow.Description = Val; });
        TryApplyStringField(RowDataObject, TEXT("MissionType"), RowName, [&](const FString& Val) { NewRow.MissionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("OwnerFilter"), RowName, [&](const FString& Val) { NewRow.OwnerFilter = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TargetFilter"), RowName, [&](const TArray<FString>& Val) { NewRow.TargetFilter = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TrackingTargetFilter"), RowName, [&](const TArray<FString>& Val) { NewRow.TrackingTargetFilter = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrackingConditionGroup"), RowName, [&](const FString& Val) { NewRow.TrackingConditionGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CustomNameArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CustomNameArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStr"), RowName, [&](const FString& Val) { NewRow.CustomStr = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStr2"), RowName, [&](const FString& Val) { NewRow.CustomStr2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("CustomInt"), RowName, [&](int32 Val) { NewRow.CustomInt = Val; });
        TryApplyIntField(RowDataObject, TEXT("CustomInt2"), RowName, [&](int32 Val) { NewRow.CustomInt2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CustomFloat"), RowName, [&](float Val) { NewRow.CustomFloat = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConditionCount"), RowName, [&](int32 Val) { NewRow.ConditionCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIType"), RowName, [&](const FString& Val) { NewRow.UIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DescriptionUIType"), RowName, [&](const FString& Val) { NewRow.DescriptionUIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("TaskConditionUIType"), RowName, [&](const FString& Val) { NewRow.TaskConditionUIType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("HideHUD"), RowName, [&](bool Val) { NewRow.HideHUD = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskStartEventTypeList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskStartEventTypeList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskStartEventSpawnAliasList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskStartEventSpawnAliasList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskCompleteEventTypeList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskCompleteEventTypeList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskCompleteEventSpawnAliasList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskCompleteEventSpawnAliasList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskProgressEventTypeList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskProgressEventTypeList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskProgressEventProgressCountList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskProgressEventProgressCountList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskProgressEventSpawnAliasList"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskProgressEventSpawnAliasList = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBQuestTaskGroupTableImporter.h"
#include "SBQuestTaskGroupTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBQuestTaskGroupTableImporter"

FString FSBQuestTaskGroupTableImporter::GetDataTableName() const
{
    return "QuestTaskGroupTable";
}

TFunction<void()> FSBQuestTaskGroupTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBQuestTaskGroupTableImporter::GetRowStruct() const
{
    return FSBQuestTaskGroupTableProperty::StaticStruct();
}

void FSBQuestTaskGroupTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBQuestTaskGroupTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description"), RowName, [&](const FString& Val) { NewRow.Description = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskContainerArray"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskContainerArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActivateEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.ActivateEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProgressEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.ProgressEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteEvent"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteEvent = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("QuestPathStartNodes"), RowName, [&](const TArray<FString>& Val) { NewRow.QuestPathStartNodes = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("QuestPathWorlds"), RowName, [&](const TArray<FString>& Val) { NewRow.QuestPathWorlds = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("QuestPathAreas"), RowName, [&](const TArray<FString>& Val) { NewRow.QuestPathAreas = Val; });
        TryApplyStringField(RowDataObject, TEXT("RestartRule"), RowName, [&](const FString& Val) { NewRow.RestartRule = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bShowGreenDot"), RowName, [&](bool Val) { NewRow.bShowGreenDot = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpType"), RowName, [&](const FString& Val) { NewRow.WarpType = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpUIDescription"), RowName, [&](const FString& Val) { NewRow.WarpUIDescription = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpConditionGroup"), RowName, [&](const FString& Val) { NewRow.WarpConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpTargetCamp"), RowName, [&](const FString& Val) { NewRow.WarpTargetCamp = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpTargetWorld"), RowName, [&](const FString& Val) { NewRow.WarpTargetWorld = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpTargetLocation"), RowName, [&](const FString& Val) { NewRow.WarpTargetLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpTargetRotation"), RowName, [&](const FString& Val) { NewRow.WarpTargetRotation = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpTargetSpawnPoint"), RowName, [&](const FString& Val) { NewRow.WarpTargetSpawnPoint = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpChoiceYesPlayTheater"), RowName, [&](const FString& Val) { NewRow.WarpChoiceYesPlayTheater = Val; });
        TryApplyStringField(RowDataObject, TEXT("WarpChoiceNoPlayTheater"), RowName, [&](const FString& Val) { NewRow.WarpChoiceNoPlayTheater = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

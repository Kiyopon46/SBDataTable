#include "Importer/FSBQuestTableImporter.h"
#include "SBQuestTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBQuestTableImporter"

FString FSBQuestTableImporter::GetDataTableName() const
{
    return "QuestTable";
}

TFunction<void()> FSBQuestTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBQuestTableImporter::GetRowStruct() const
{
    return FSBQuestTableProperty::StaticStruct();
}

void FSBQuestTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBQuestTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestType"), RowName, [&](const FString& Val) { NewRow.QuestType = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestUIType"), RowName, [&](const FString& Val) { NewRow.QuestUIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("RequestType"), RowName, [&](const FString& Val) { NewRow.RequestType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayRequestBoardType"), RowName, [&](const FString& Val) { NewRow.DisplayRequestBoardType = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextQuest"), RowName, [&](const FString& Val) { NewRow.NextQuest = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleName_"), RowName, [&](const FString& Val) { NewRow.TitleName_ = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description_"), RowName, [&](const FString& Val) { NewRow.Description_ = Val; });
        TryApplyStringField(RowDataObject, TEXT("RequestDescription"), RowName, [&](const FString& Val) { NewRow.RequestDescription = Val; });
        TryApplyStringField(RowDataObject, TEXT("Report"), RowName, [&](const FString& Val) { NewRow.Report = Val; });
        TryApplyStringField(RowDataObject, TEXT("Reward"), RowName, [&](const FString& Val) { NewRow.Reward = Val; });
        TryApplyStringField(RowDataObject, TEXT("FailAchievementCondition"), RowName, [&](const FString& Val) { NewRow.FailAchievementCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("FailConditionGroup"), RowName, [&](const FString& Val) { NewRow.FailConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FailConditionEventType"), RowName, [&](const FString& Val) { NewRow.FailConditionEventType = Val; });
        TryApplyStringField(RowDataObject, TEXT("FailConditionResultType"), RowName, [&](const FString& Val) { NewRow.FailConditionResultType = Val; });
        TryApplyStringField(RowDataObject, TEXT("AvailableConditionGroup"), RowName, [&](const FString& Val) { NewRow.AvailableConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("ValidConditionGroup"), RowName, [&](const FString& Val) { NewRow.ValidConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("AcquireSound"), RowName, [&](const FString& Val) { NewRow.AcquireSound = Val; });
        TryApplyStringField(RowDataObject, TEXT("AcquireSubtitleType"), RowName, [&](const FString& Val) { NewRow.AcquireSubtitleType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AcquireSubtitleDuration"), RowName, [&](float Val) { NewRow.AcquireSubtitleDuration = Val; });
        TryApplyStringField(RowDataObject, TEXT("AcquireSubtitleTitle"), RowName, [&](const FString& Val) { NewRow.AcquireSubtitleTitle = Val; });
        TryApplyStringField(RowDataObject, TEXT("AcquireSubtitleMessage"), RowName, [&](const FString& Val) { NewRow.AcquireSubtitleMessage = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RequiredQuestArray"), RowName, [&](const TArray<FString>& Val) { NewRow.RequiredQuestArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TaskGroupAlias"), RowName, [&](const TArray<FString>& Val) { NewRow.TaskGroupAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AcquireEventArray"), RowName, [&](const TArray<FString>& Val) { NewRow.AcquireEventArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteEventArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteEventArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("QuestPathStartNodes"), RowName, [&](const TArray<FString>& Val) { NewRow.QuestPathStartNodes = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("QuestPathWorlds"), RowName, [&](const TArray<FString>& Val) { NewRow.QuestPathWorlds = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AcquireEventActionTypeList"), RowName, [&](const TArray<FString>& Val) { NewRow.AcquireEventActionTypeList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AcquireEventActionAliasList"), RowName, [&](const TArray<FString>& Val) { NewRow.AcquireEventActionAliasList = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMaintainNewGamePlus"), RowName, [&](bool Val) { NewRow.bMaintainNewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

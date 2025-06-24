#include "Importer/FSBGamePlayProgressRecordTableImporter.h"
#include "SBGamePlayProgressRecordTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBGamePlayProgressRecordTableImporter"

FString FSBGamePlayProgressRecordTableImporter::GetDataTableName() const
{
    return "GamePlayProgressRecordTable";
}

TFunction<void()> FSBGamePlayProgressRecordTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBGamePlayProgressRecordTableImporter::GetRowStruct() const
{
    return FSBGamePlayProgressRecordTableProperty::StaticStruct();
}

void FSBGamePlayProgressRecordTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBGamePlayProgressRecordTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestTaskGroup"), RowName, [&](const FString& Val) { NewRow.QuestTaskGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestTaskType"), RowName, [&](const FString& Val) { NewRow.QuestTaskType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DataAlias"), RowName, [&](const FString& Val) { NewRow.DataAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnvState"), RowName, [&](const FString& Val) { NewRow.EnvState = Val; });
        TryApplyStringField(RowDataObject, TEXT("Enable"), RowName, [&](const FString& Val) { NewRow.Enable = Val; });
        TryApplyStringField(RowDataObject, TEXT("Zone"), RowName, [&](const FString& Val) { NewRow.Zone = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionKey"), RowName, [&](const FString& Val) { NewRow.InteractionKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionValue"), RowName, [&](const FString& Val) { NewRow.InteractionValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("RecordFilterType"), RowName, [&](const FString& Val) { NewRow.RecordFilterType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DebugTargetCamp"), RowName, [&](const FString& Val) { NewRow.DebugTargetCamp = Val; });
        TryApplyStringField(RowDataObject, TEXT("DebugSpawnPoint"), RowName, [&](const FString& Val) { NewRow.DebugSpawnPoint = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommands"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommands = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommands2"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommands2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommands3"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommands3 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommands4"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommands4 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommandsForNewGamePlus"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommandsForNewGamePlus = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommandsForNewGamePlus2"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommandsForNewGamePlus2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommandsForNewGamePlus3"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommandsForNewGamePlus3 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DebugCommandsForNewGamePlus4"), RowName, [&](const TArray<FString>& Val) { NewRow.DebugCommandsForNewGamePlus4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

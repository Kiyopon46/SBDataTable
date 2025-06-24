#include "Importer/FSBCheatProgressQuestCommandsTableImporter.h"
#include "SBCheatProgressQuestCommandsTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCheatProgressQuestCommandsTableImporter"

FString FSBCheatProgressQuestCommandsTableImporter::GetDataTableName() const
{
    return "CheatProgressQuestCommandsTable";
}

TFunction<void()> FSBCheatProgressQuestCommandsTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCheatProgressQuestCommandsTableImporter::GetRowStruct() const
{
    return FSBCheatProgressQuestCommandsTableProperty::StaticStruct();
}

void FSBCheatProgressQuestCommandsTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCheatProgressQuestCommandsTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteQuestList"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteQuestList = Val; });
        TryApplyStringField(RowDataObject, TEXT("GamePlayProgressRecord"), RowName, [&](const FString& Val) { NewRow.GamePlayProgressRecord = Val; });
        TryApplyIntField(RowDataObject, TEXT("QuestPathIndex"), RowName, [&](int32 Val) { NewRow.QuestPathIndex = Val; });
        TryApplyIntField(RowDataObject, TEXT("QuestPathNodeIndex"), RowName, [&](int32 Val) { NewRow.QuestPathNodeIndex = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

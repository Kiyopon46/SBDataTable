#include "Importer/FSBGamePlayProgressCheatTableImporter.h"
#include "SBGamePlayProgressCheatTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBGamePlayProgressCheatTableImporter"

FString FSBGamePlayProgressCheatTableImporter::GetDataTableName() const
{
    return "GamePlayProgressCheatTable";
}

TFunction<void()> FSBGamePlayProgressCheatTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBGamePlayProgressCheatTableImporter::GetRowStruct() const
{
    return FSBGamePlayProgressCheatTableProperty::StaticStruct();
}

void FSBGamePlayProgressCheatTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBGamePlayProgressCheatTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandGroup"), RowName, [&](const FString& Val) { NewRow.CommandGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("PreCommand"), RowName, [&](const FString& Val) { NewRow.PreCommand = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot1"), RowName, [&](const FString& Val) { NewRow.CommandSlot1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot1NewGamePlus"), RowName, [&](const FString& Val) { NewRow.CommandSlot1NewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot2"), RowName, [&](const FString& Val) { NewRow.CommandSlot2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot2NewGamePlus"), RowName, [&](const FString& Val) { NewRow.CommandSlot2NewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot3"), RowName, [&](const FString& Val) { NewRow.CommandSlot3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot3NewGamePlus"), RowName, [&](const FString& Val) { NewRow.CommandSlot3NewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot4"), RowName, [&](const FString& Val) { NewRow.CommandSlot4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CommandSlot4NewGamePlus"), RowName, [&](const FString& Val) { NewRow.CommandSlot4NewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("PostCommand"), RowName, [&](const FString& Val) { NewRow.PostCommand = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBSoundEventQuestTableImporter.h"
#include "SBSoundEventQuestTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSoundEventQuestTableImporter"

FString FSBSoundEventQuestTableImporter::GetDataTableName() const
{
    return "SoundEventQuestTable";
}

TFunction<void()> FSBSoundEventQuestTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSoundEventQuestTableImporter::GetRowStruct() const
{
    return FSBSoundEventQuestTableProperty::StaticStruct();
}

void FSBSoundEventQuestTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSoundEventQuestTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("QuestAcquireSoundEvent"), RowName, [&](const FString& Val) { NewRow.QuestAcquireSoundEvent = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestCompleteSoundEvent"), RowName, [&](const FString& Val) { NewRow.QuestCompleteSoundEvent = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

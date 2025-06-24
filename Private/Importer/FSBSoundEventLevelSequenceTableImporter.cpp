#include "Importer/FSBSoundEventLevelSequenceTableImporter.h"
#include "SBSoundEventLevelSequenceTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSoundEventLevelSequenceTableImporter"

FString FSBSoundEventLevelSequenceTableImporter::GetDataTableName() const
{
    return "SoundEventLevelSequenceTable";
}

TFunction<void()> FSBSoundEventLevelSequenceTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSoundEventLevelSequenceTableImporter::GetRowStruct() const
{
    return FSBSoundEventLevelSequenceTableProperty::StaticStruct();
}

void FSBSoundEventLevelSequenceTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSoundEventLevelSequenceTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceBeginSoundEvent"), RowName, [&](const FString& Val) { NewRow.LevelSequenceBeginSoundEvent = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BeginSoundEventDelayTime"), RowName, [&](float Val) { NewRow.BeginSoundEventDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceFinishSoundEvent"), RowName, [&](const FString& Val) { NewRow.LevelSequenceFinishSoundEvent = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FinishSoundEventDelayTime"), RowName, [&](float Val) { NewRow.FinishSoundEventDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("SoundMixPath"), RowName, [&](const FString& Val) { NewRow.SoundMixPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

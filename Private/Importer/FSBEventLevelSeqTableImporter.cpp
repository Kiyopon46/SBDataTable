#include "Importer/FSBEventLevelSeqTableImporter.h"
#include "SBZoneEventLevelSeqTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventLevelSeqTableImporter"

FString FSBEventLevelSeqTableImporter::GetDataTableName() const
{
    return "EventLevelSeqTable";
}

TFunction<void()> FSBEventLevelSeqTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventLevelSeqTableImporter::GetRowStruct() const
{
    return FSBZoneEventLevelSeqTableProperty::StaticStruct();
}

void FSBEventLevelSeqTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventLevelSeqTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSeqAlias"), RowName, [&](const FString& Val) { NewRow.LevelSeqAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequencePath"), RowName, [&](const FString& Val) { NewRow.LevelSequencePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AttachTagNames"), RowName, [&](const TArray<FString>& Val) { NewRow.AttachTagNames = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bStopEndFrame"), RowName, [&](bool Val) { NewRow.bStopEndFrame = Val; });
        TryApplyStringField(RowDataObject, TEXT("SequenceTemplatePath"), RowName, [&](const FString& Val) { NewRow.SequenceTemplatePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventorType"), RowName, [&](const FString& Val) { NewRow.EventorType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDontStopResetZone"), RowName, [&](bool Val) { NewRow.bDontStopResetZone = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceContentsType"), RowName, [&](const FString& Val) { NewRow.LevelSequenceContentsType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("StartMovementNone"), RowName, [&](bool Val) { NewRow.StartMovementNone = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });
        TryApplyBoolField(RowDataObject, TEXT("UseRandomSequence"), RowName, [&](bool Val) { NewRow.UseRandomSequence = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RandomLevelSequencePaths"), RowName, [&](const TArray<FString>& Val) { NewRow.RandomLevelSequencePaths = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBSoundAttenuationEventTableImporter.h"
#include "SBSoundAttenuationEventTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSoundAttenuationEventTableImporter"

FString FSBSoundAttenuationEventTableImporter::GetDataTableName() const
{
    return "SoundAttenuationEventTable";
}

TFunction<void()> FSBSoundAttenuationEventTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSoundAttenuationEventTableImporter::GetRowStruct() const
{
    return FSBSoundAttenuationEventTableProperty::StaticStruct();
}

void FSBSoundAttenuationEventTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSoundAttenuationEventTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("Editor_Description"), RowName, [&](const FString& Val) { NewRow.Editor_Description = Val; });
        TryApplyStringField(RowDataObject, TEXT("DialogAttenuationPath"), RowName, [&](const FString& Val) { NewRow.DialogAttenuationPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActionVoiceAttenuationPath"), RowName, [&](const FString& Val) { NewRow.ActionVoiceAttenuationPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FootstepAttenuationPath"), RowName, [&](const FString& Val) { NewRow.FootstepAttenuationPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

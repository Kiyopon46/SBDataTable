#include "Importer/FSBSoundEventTableImporter.h"
#include "SBSoundEventTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSoundEventTableImporter"

FString FSBSoundEventTableImporter::GetDataTableName() const
{
    return "SoundEventTable";
}

TFunction<void()> FSBSoundEventTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSoundEventTableImporter::GetRowStruct() const
{
    return FSBSoundEventTableProperty::StaticStruct();
}

void FSBSoundEventTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSoundEventTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("MainBGMPath"), RowName, [&](const FString& Val) { NewRow.MainBGMPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("AmbientBGMPath"), RowName, [&](const FString& Val) { NewRow.AmbientBGMPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("SoundStateRule"), RowName, [&](const FString& Val) { NewRow.SoundStateRule = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventBattleState"), RowName, [&](const FString& Val) { NewRow.EventBattleState = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("IntParams"), RowName, [&](const TArray<FString>& Val) { NewRow.IntParams = Val; });
        TryApplyStringField(RowDataObject, TEXT("SoundBasePath"), RowName, [&](const FString& Val) { NewRow.SoundBasePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttachActorTag"), RowName, [&](const FString& Val) { NewRow.AttachActorTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttachSocket"), RowName, [&](const FString& Val) { NewRow.AttachSocket = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttenuationEventAlias"), RowName, [&](const FString& Val) { NewRow.AttenuationEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

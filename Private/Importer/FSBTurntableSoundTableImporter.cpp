#include "Importer/FSBTurntableSoundTableImporter.h"
#include "SBTurntableSoundTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBTurntableSoundTableImporter"

FString FSBTurntableSoundTableImporter::GetDataTableName() const
{
    return "TurntableSoundTable";
}

TFunction<void()> FSBTurntableSoundTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBTurntableSoundTableImporter::GetRowStruct() const
{
    return FSBTurntableSoundTableProperty::StaticStruct();
}

void FSBTurntableSoundTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBTurntableSoundTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("NotifyAchievement"), RowName, [&](const FString& Val) { NewRow.NotifyAchievement = Val; });
        TryApplyStringField(RowDataObject, TEXT("MusicPath"), RowName, [&](const FString& Val) { NewRow.MusicPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("NoiseMusicPath"), RowName, [&](const FString& Val) { NewRow.NoiseMusicPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleStringKey"), RowName, [&](const FString& Val) { NewRow.TitleStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ImagePath"), RowName, [&](const FString& Val) { NewRow.ImagePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("QNRTAssetPath"), RowName, [&](const FString& Val) { NewRow.QNRTAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

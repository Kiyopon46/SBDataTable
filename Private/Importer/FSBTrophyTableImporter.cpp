#include "Importer/FSBTrophyTableImporter.h"
#include "SBTrophyTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBTrophyTableImporter"

FString FSBTrophyTableImporter::GetDataTableName() const
{
    return "TrophyTable";
}

TFunction<void()> FSBTrophyTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBTrophyTableImporter::GetRowStruct() const
{
    return FSBTrophyTableProperty::StaticStruct();
}

void FSBTrophyTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBTrophyTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrophyGroup"), RowName, [&](const FString& Val) { NewRow.TrophyGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("Name"), RowName, [&](const FString& Val) { NewRow.Name = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Hidden"), RowName, [&](bool Val) { NewRow.Hidden = Val; });
        TryApplyStringField(RowDataObject, TEXT("grade"), RowName, [&](const FString& Val) { NewRow.grade = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProgressAchievement"), RowName, [&](const FString& Val) { NewRow.ProgressAchievement = Val; });
        TryApplyIntField(RowDataObject, TEXT("CompleteValue"), RowName, [&](int32 Val) { NewRow.CompleteValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayName_StringKey"), RowName, [&](const FString& Val) { NewRow.DisplayName_StringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayDescription_StringKey"), RowName, [&](const FString& Val) { NewRow.DisplayDescription_StringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayName_en_us"), RowName, [&](const FString& Val) { NewRow.DisplayName_en_us = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayDescription_en_us"), RowName, [&](const FString& Val) { NewRow.DisplayDescription_en_us = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayName_ko_kr"), RowName, [&](const FString& Val) { NewRow.DisplayName_ko_kr = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayDescription_ko_kr"), RowName, [&](const FString& Val) { NewRow.DisplayDescription_ko_kr = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

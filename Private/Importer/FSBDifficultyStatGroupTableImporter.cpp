#include "Importer/FSBDifficultyStatGroupTableImporter.h"
#include "SBDifficultyStatGroupTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBDifficultyStatGroupTableImporter"

FString FSBDifficultyStatGroupTableImporter::GetDataTableName() const
{
    return "DifficultyStatGroupTable";
}

TFunction<void()> FSBDifficultyStatGroupTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBDifficultyStatGroupTableImporter::GetRowStruct() const
{
    return FSBDifficultyStatGroupTableProperty::StaticStruct();
}

void FSBDifficultyStatGroupTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBDifficultyStatGroupTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("DifficultyAlias"), RowName, [&](const FString& Val) { NewRow.DifficultyAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("DifficultyStatGroupAlias"), RowName, [&](const FString& Val) { NewRow.DifficultyStatGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat1"), RowName, [&](const FString& Val) { NewRow.Stat1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType1"), RowName, [&](const FString& Val) { NewRow.StatCalculationType1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue1"), RowName, [&](float Val) { NewRow.StatValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat2"), RowName, [&](const FString& Val) { NewRow.Stat2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType2"), RowName, [&](const FString& Val) { NewRow.StatCalculationType2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue2"), RowName, [&](float Val) { NewRow.StatValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat3"), RowName, [&](const FString& Val) { NewRow.Stat3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType3"), RowName, [&](const FString& Val) { NewRow.StatCalculationType3 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue3"), RowName, [&](float Val) { NewRow.StatValue3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat4"), RowName, [&](const FString& Val) { NewRow.Stat4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType4"), RowName, [&](const FString& Val) { NewRow.StatCalculationType4 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue4"), RowName, [&](float Val) { NewRow.StatValue4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat5"), RowName, [&](const FString& Val) { NewRow.Stat5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType5"), RowName, [&](const FString& Val) { NewRow.StatCalculationType5 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue5"), RowName, [&](float Val) { NewRow.StatValue5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat6"), RowName, [&](const FString& Val) { NewRow.Stat6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType6"), RowName, [&](const FString& Val) { NewRow.StatCalculationType6 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue6"), RowName, [&](float Val) { NewRow.StatValue6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat7"), RowName, [&](const FString& Val) { NewRow.Stat7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType7"), RowName, [&](const FString& Val) { NewRow.StatCalculationType7 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue7"), RowName, [&](float Val) { NewRow.StatValue7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat8"), RowName, [&](const FString& Val) { NewRow.Stat8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCalculationType8"), RowName, [&](const FString& Val) { NewRow.StatCalculationType8 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValue8"), RowName, [&](float Val) { NewRow.StatValue8 = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

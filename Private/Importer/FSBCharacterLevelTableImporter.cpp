#include "Importer/FSBCharacterLevelTableImporter.h"
#include "SBCharacterLevelTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterLevelTableImporter"

FString FSBCharacterLevelTableImporter::GetDataTableName() const
{
    return "CharacterLevelTable";
}

TFunction<void()> FSBCharacterLevelTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterLevelTableImporter::GetRowStruct() const
{
    return FSBCharacterLevelTableProperty::StaticStruct();
}

void FSBCharacterLevelTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterLevelTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("LevelType"), RowName, [&](const FString& Val) { NewRow.LevelType = Val; });
        TryApplyIntField(RowDataObject, TEXT("Level"), RowName, [&](int32 Val) { NewRow.Level = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat1"), RowName, [&](const FString& Val) { NewRow.Stat1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StatValue1"), RowName, [&](int32 Val) { NewRow.StatValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Stat2"), RowName, [&](const FString& Val) { NewRow.Stat2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("StatValue2"), RowName, [&](int32 Val) { NewRow.StatValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RequiredItemAlias1"), RowName, [&](const FString& Val) { NewRow.RequiredItemAlias1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("RequiredItemAmount1"), RowName, [&](int32 Val) { NewRow.RequiredItemAmount1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("RequiredItemAlias2"), RowName, [&](const FString& Val) { NewRow.RequiredItemAlias2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("RequiredItemAmount2"), RowName, [&](int32 Val) { NewRow.RequiredItemAmount2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultDescription"), RowName, [&](const FString& Val) { NewRow.ResultDescription = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

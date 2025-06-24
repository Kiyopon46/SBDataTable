#include "Importer/FSBCharacterTribeTableImporter.h"
#include "SBCharacterTribeTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterTribeTableImporter"

FString FSBCharacterTribeTableImporter::GetDataTableName() const
{
    return "CharacterTribeTable";
}

TFunction<void()> FSBCharacterTribeTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterTribeTableImporter::GetRowStruct() const
{
    return FSBCharacterTribeTableProperty::StaticStruct();
}

void FSBCharacterTribeTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterTribeTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe1"), RowName, [&](const FString& Val) { NewRow.TargetTribe1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation1"), RowName, [&](const FString& Val) { NewRow.TargetRelation1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe2"), RowName, [&](const FString& Val) { NewRow.TargetTribe2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation2"), RowName, [&](const FString& Val) { NewRow.TargetRelation2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe3"), RowName, [&](const FString& Val) { NewRow.TargetTribe3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation3"), RowName, [&](const FString& Val) { NewRow.TargetRelation3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe4"), RowName, [&](const FString& Val) { NewRow.TargetTribe4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation4"), RowName, [&](const FString& Val) { NewRow.TargetRelation4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe5"), RowName, [&](const FString& Val) { NewRow.TargetTribe5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation5"), RowName, [&](const FString& Val) { NewRow.TargetRelation5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe6"), RowName, [&](const FString& Val) { NewRow.TargetTribe6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation6"), RowName, [&](const FString& Val) { NewRow.TargetRelation6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe7"), RowName, [&](const FString& Val) { NewRow.TargetTribe7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation7"), RowName, [&](const FString& Val) { NewRow.TargetRelation7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe8"), RowName, [&](const FString& Val) { NewRow.TargetTribe8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation8"), RowName, [&](const FString& Val) { NewRow.TargetRelation8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe9"), RowName, [&](const FString& Val) { NewRow.TargetTribe9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation9"), RowName, [&](const FString& Val) { NewRow.TargetRelation9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTribe10"), RowName, [&](const FString& Val) { NewRow.TargetTribe10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetRelation10"), RowName, [&](const FString& Val) { NewRow.TargetRelation10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

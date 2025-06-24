#include "Importer/FSBTransformCharacterTableImporter.h"
#include "SBTransformCharacterTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBTransformCharacterTableImporter"

FString FSBTransformCharacterTableImporter::GetDataTableName() const
{
    return "TransformCharacterTable";
}

TFunction<void()> FSBTransformCharacterTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBTransformCharacterTableImporter::GetRowStruct() const
{
    return FSBTransformCharacterTableProperty::StaticStruct();
}

void FSBTransformCharacterTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBTransformCharacterTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("Score"), RowName, [&](int32 Val) { NewRow.Score = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias1"), RowName, [&](const FString& Val) { NewRow.CharacterAlias1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight1"), RowName, [&](int32 Val) { NewRow.Weight1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias2"), RowName, [&](const FString& Val) { NewRow.CharacterAlias2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight2"), RowName, [&](int32 Val) { NewRow.Weight2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias3"), RowName, [&](const FString& Val) { NewRow.CharacterAlias3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight3"), RowName, [&](int32 Val) { NewRow.Weight3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias4"), RowName, [&](const FString& Val) { NewRow.CharacterAlias4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight4"), RowName, [&](int32 Val) { NewRow.Weight4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias5"), RowName, [&](const FString& Val) { NewRow.CharacterAlias5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight5"), RowName, [&](int32 Val) { NewRow.Weight5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias6"), RowName, [&](const FString& Val) { NewRow.CharacterAlias6 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight6"), RowName, [&](int32 Val) { NewRow.Weight6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias7"), RowName, [&](const FString& Val) { NewRow.CharacterAlias7 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight7"), RowName, [&](int32 Val) { NewRow.Weight7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias8"), RowName, [&](const FString& Val) { NewRow.CharacterAlias8 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight8"), RowName, [&](int32 Val) { NewRow.Weight8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias9"), RowName, [&](const FString& Val) { NewRow.CharacterAlias9 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight9"), RowName, [&](int32 Val) { NewRow.Weight9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAlias10"), RowName, [&](const FString& Val) { NewRow.CharacterAlias10 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Weight10"), RowName, [&](int32 Val) { NewRow.Weight10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

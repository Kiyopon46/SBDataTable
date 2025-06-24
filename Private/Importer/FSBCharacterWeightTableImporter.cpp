#include "Importer/FSBCharacterWeightTableImporter.h"
#include "SBCharacterWeightTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterWeightTableImporter"

FString FSBCharacterWeightTableImporter::GetDataTableName() const
{
    return "CharacterWeightTable";
}

TFunction<void()> FSBCharacterWeightTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterWeightTableImporter::GetRowStruct() const
{
    return FSBCharacterWeightTableProperty::StaticStruct();
}

void FSBCharacterWeightTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterWeightTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Small_MoveXY"), RowName, [&](float Val) { NewRow.Small_MoveXY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Small_MoveZ"), RowName, [&](float Val) { NewRow.Small_MoveZ = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Normal_MoveXY"), RowName, [&](float Val) { NewRow.Normal_MoveXY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Normal_MoveZ"), RowName, [&](float Val) { NewRow.Normal_MoveZ = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Medium_MoveXY"), RowName, [&](float Val) { NewRow.Medium_MoveXY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Medium_MoveZ"), RowName, [&](float Val) { NewRow.Medium_MoveZ = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Large_MoveXY"), RowName, [&](float Val) { NewRow.Large_MoveXY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Large_MoveZ"), RowName, [&](float Val) { NewRow.Large_MoveZ = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SuperLarge_MoveXY"), RowName, [&](float Val) { NewRow.SuperLarge_MoveXY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SuperLarge_MoveZ"), RowName, [&](float Val) { NewRow.SuperLarge_MoveZ = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

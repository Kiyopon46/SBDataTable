#include "Importer/FSBEquipStatViewerTableImporter.h"
#include "SBEquipStatViewerTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEquipStatViewerTableImporter"

FString FSBEquipStatViewerTableImporter::GetDataTableName() const
{
    return "EquipStatViewerTable";
}

TFunction<void()> FSBEquipStatViewerTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEquipStatViewerTableImporter::GetRowStruct() const
{
    return FSBEquipStatViewerTableProperty::StaticStruct();
}

void FSBEquipStatViewerTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEquipStatViewerTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatType"), RowName, [&](const FString& Val) { NewRow.StatType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CalculatedStatType"), RowName, [&](const FString& Val) { NewRow.CalculatedStatType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinValue"), RowName, [&](float Val) { NewRow.MinValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxValue"), RowName, [&](float Val) { NewRow.MaxValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxValueInNewGamePlus"), RowName, [&](float Val) { NewRow.MaxValueInNewGamePlus = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DisplayMaxValue"), RowName, [&](bool Val) { NewRow.DisplayMaxValue = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DisplayMaxTag"), RowName, [&](bool Val) { NewRow.DisplayMaxTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnhanceCharLevelType"), RowName, [&](const FString& Val) { NewRow.EnhanceCharLevelType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DisplayEnhanceCharLevel"), RowName, [&](bool Val) { NewRow.DisplayEnhanceCharLevel = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DisplayAlways"), RowName, [&](bool Val) { NewRow.DisplayAlways = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DontDisplayUI"), RowName, [&](bool Val) { NewRow.DontDisplayUI = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DisplayDecimal"), RowName, [&](bool Val) { NewRow.DisplayDecimal = Val; });
        TryApplyStringField(RowDataObject, TEXT("Achievement"), RowName, [&](const FString& Val) { NewRow.Achievement = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBCharacterDetectAITableImporter.h"
#include "SBCharacterDetectAITableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterDetectAITableImporter"

FString FSBCharacterDetectAITableImporter::GetDataTableName() const
{
    return "CharacterDetectAITable";
}

TFunction<void()> FSBCharacterDetectAITableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterDetectAITableImporter::GetRowStruct() const
{
    return FSBCharacterDetectAITableProperty::StaticStruct();
}

void FSBCharacterDetectAITableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterDetectAITableProperty NewRow;
        TryApplyFloatField(RowDataObject, TEXT("AISightSenseHorizontalAngle"), RowName, [&](float Val) { NewRow.AISightSenseHorizontalAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AISightSenseVerticalAngle"), RowName, [&](float Val) { NewRow.AISightSenseVerticalAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AISightSenseNearDistance"), RowName, [&](float Val) { NewRow.AISightSenseNearDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AISightSenseVerticalDistance"), RowName, [&](float Val) { NewRow.AISightSenseVerticalDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AISightSenseIgnoreBlocking"), RowName, [&](bool Val) { NewRow.AISightSenseIgnoreBlocking = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AISightSenseIgnoreBlockingWhenDetectTarget"), RowName, [&](bool Val) { NewRow.AISightSenseIgnoreBlockingWhenDetectTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIDetectCheckDistance"), RowName, [&](float Val) { NewRow.AIDetectCheckDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIObserveCheckDistance"), RowName, [&](float Val) { NewRow.AIObserveCheckDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIPursuitDistance"), RowName, [&](float Val) { NewRow.AIPursuitDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIPursuitFixedDistance"), RowName, [&](float Val) { NewRow.AIPursuitFixedDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIPursuitVerticaDistance"), RowName, [&](float Val) { NewRow.AIPursuitVerticaDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIIncreaseAggroGaguePerSecond"), RowName, [&](float Val) { NewRow.AIIncreaseAggroGaguePerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIIncreaseDoubtAggroGaguePerSecond"), RowName, [&](float Val) { NewRow.AIIncreaseDoubtAggroGaguePerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIDecreaseLevel0AggroGaguePerSecond"), RowName, [&](float Val) { NewRow.AIDecreaseLevel0AggroGaguePerSecond = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AIDecreaseLevel1AggroGaguePerSecond"), RowName, [&](float Val) { NewRow.AIDecreaseLevel1AggroGaguePerSecond = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

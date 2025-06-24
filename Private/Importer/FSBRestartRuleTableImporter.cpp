#include "Importer/FSBRestartRuleTableImporter.h"
#include "SBRestartRuleTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBRestartRuleTableImporter"

FString FSBRestartRuleTableImporter::GetDataTableName() const
{
    return "RestartRuleTable";
}

TFunction<void()> FSBRestartRuleTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBRestartRuleTableImporter::GetRowStruct() const
{
    return FSBRestartRuleTableProperty::StaticStruct();
}

void FSBRestartRuleTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBRestartRuleTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("MainLevelTarget"), RowName, [&](const FString& Val) { NewRow.MainLevelTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("LookAtLevelTarget"), RowName, [&](const FString& Val) { NewRow.LookAtLevelTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SafetyDistance"), RowName, [&](float Val) { NewRow.SafetyDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OutsideLimitTime"), RowName, [&](float Val) { NewRow.OutsideLimitTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("OutSideLevelSequence"), RowName, [&](const FString& Val) { NewRow.OutSideLevelSequence = Val; });
        TryApplyStringField(RowDataObject, TEXT("OutSideTheaterEvent"), RowName, [&](const FString& Val) { NewRow.OutSideTheaterEvent = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBTheaterSelectDataTableImporter.h"
#include "SBTheaterSelectDataTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBTheaterSelectDataTableImporter"

FString FSBTheaterSelectDataTableImporter::GetDataTableName() const
{
    return "TheaterSelectDataTable";
}

TFunction<void()> FSBTheaterSelectDataTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBTheaterSelectDataTableImporter::GetRowStruct() const
{
    return FSBTheaterSelectDataTableProperty::StaticStruct();
}

void FSBTheaterSelectDataTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBTheaterSelectDataTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("SelectDataName"), RowName, [&](const FString& Val) { NewRow.SelectDataName = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Conditions"), RowName, [&](const TArray<FString>& Val) { NewRow.Conditions = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("DesignType"), RowName, [&](const FString& Val) { NewRow.DesignType = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleMessageText"), RowName, [&](const FString& Val) { NewRow.TitleMessageText = Val; });
        TryApplyStringField(RowDataObject, TEXT("TextVisibleType"), RowName, [&](const FString& Val) { NewRow.TextVisibleType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayText"), RowName, [&](const FString& Val) { NewRow.DisplayText = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextTaskTagName"), RowName, [&](const FString& Val) { NewRow.NextTaskTagName = Val; });
        TryApplyIntField(RowDataObject, TEXT("SelectDataPriority"), RowName, [&](int32 Val) { NewRow.SelectDataPriority = Val; });
        TryApplyStringField(RowDataObject, TEXT("InteractionGraphExec"), RowName, [&](const FString& Val) { NewRow.InteractionGraphExec = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseInputCancel"), RowName, [&](bool Val) { NewRow.bUseInputCancel = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestSymbolType"), RowName, [&](const FString& Val) { NewRow.QuestSymbolType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("QuestSymbol_VisibilityConditionGorup"), RowName, [&](const TArray<FString>& Val) { NewRow.QuestSymbol_VisibilityConditionGorup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bForceLock"), RowName, [&](bool Val) { NewRow.bForceLock = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableRelevantDot"), RowName, [&](bool Val) { NewRow.bDisableRelevantDot = Val; });
        TryApplyStringField(RowDataObject, TEXT("SelectedMessagePopupText"), RowName, [&](const FString& Val) { NewRow.SelectedMessagePopupText = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description"), RowName, [&](const FString& Val) { NewRow.Description = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

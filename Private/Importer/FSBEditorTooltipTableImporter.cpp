#include "Importer/FSBEditorTooltipTableImporter.h"
#include "SBEditorTooltipTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEditorTooltipTableImporter"

FString FSBEditorTooltipTableImporter::GetDataTableName() const
{
    return "EditorTooltipTable";
}

TFunction<void()> FSBEditorTooltipTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEditorTooltipTableImporter::GetRowStruct() const
{
    return FSBEditorTooltipTableProperty::StaticStruct();
}

void FSBEditorTooltipTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEditorTooltipTableProperty NewRow;
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyStringField(RowDataObject, TEXT("Target"), RowName, [&](const FString& Val) { NewRow.Target = Val; });
        TryApplyStringField(RowDataObject, TEXT("FieldName"), RowName, [&](const FString& Val) { NewRow.FieldName = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FieldNameArray"), RowName, [&](const TArray<FString>& Val) { NewRow.FieldNameArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

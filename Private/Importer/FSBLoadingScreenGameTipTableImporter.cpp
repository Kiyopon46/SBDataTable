#include "Importer/FSBLoadingScreenGameTipTableImporter.h"
#include "SBLoadingScreenGameTipTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBLoadingScreenGameTipTableImporter"

FString FSBLoadingScreenGameTipTableImporter::GetDataTableName() const
{
    return "LoadingScreenGameTipTable";
}

TFunction<void()> FSBLoadingScreenGameTipTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBLoadingScreenGameTipTableImporter::GetRowStruct() const
{
    return FSBLoadingScreenGameTipTableProperty::StaticStruct();
}

void FSBLoadingScreenGameTipTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBLoadingScreenGameTipTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description"), RowName, [&](const FString& Val) { NewRow.Description = Val; });
        TryApplyStringField(RowDataObject, TEXT("TipGroup"), RowName, [&](const FString& Val) { NewRow.TipGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("Condition"), RowName, [&](const FString& Val) { NewRow.Condition = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

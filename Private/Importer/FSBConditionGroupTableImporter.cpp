#include "Importer/FSBConditionGroupTableImporter.h"
#include "SBConditionGroupTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBConditionGroupTableImporter"

FString FSBConditionGroupTableImporter::GetDataTableName() const
{
    return "ConditionGroupTable";
}

TFunction<void()> FSBConditionGroupTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBConditionGroupTableImporter::GetRowStruct() const
{
    return FSBConditionGroupTableProperty::StaticStruct();
}

void FSBConditionGroupTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBConditionGroupTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Conditions"), RowName, [&](const TArray<FString>& Val) { NewRow.Conditions = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEq"), RowName, [&](const FString& Val) { NewRow.ConditionEq = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup1"), RowName, [&](const FString& Val) { NewRow.ConditionGroup1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupEq1"), RowName, [&](const FString& Val) { NewRow.GroupEq1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup2"), RowName, [&](const FString& Val) { NewRow.ConditionGroup2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupEq2"), RowName, [&](const FString& Val) { NewRow.GroupEq2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

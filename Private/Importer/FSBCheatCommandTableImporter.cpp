#include "Importer/FSBCheatCommandTableImporter.h"
#include "SBCheatCommandTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCheatCommandTableImporter"

FString FSBCheatCommandTableImporter::GetDataTableName() const
{
    return "CheatCommandTable";
}

TFunction<void()> FSBCheatCommandTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCheatCommandTableImporter::GetRowStruct() const
{
    return FSBCheatCommandTableProperty::StaticStruct();
}

void FSBCheatCommandTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCheatCommandTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Distribution"), RowName, [&](const FString& Val) { NewRow.Distribution = Val; });
        TryApplyStringField(RowDataObject, TEXT("Tab"), RowName, [&](const FString& Val) { NewRow.Tab = Val; });
        TryApplyStringField(RowDataObject, TEXT("TabName"), RowName, [&](const FString& Val) { NewRow.TabName = Val; });
        TryApplyStringField(RowDataObject, TEXT("Category"), RowName, [&](const FString& Val) { NewRow.Category = Val; });
        TryApplyStringField(RowDataObject, TEXT("CategoryName"), RowName, [&](const FString& Val) { NewRow.CategoryName = Val; });
        TryApplyStringField(RowDataObject, TEXT("CategoryStringKey"), RowName, [&](const FString& Val) { NewRow.CategoryStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("Desc"), RowName, [&](const FString& Val) { NewRow.Desc = Val; });
        TryApplyStringField(RowDataObject, TEXT("DescStringKey"), RowName, [&](const FString& Val) { NewRow.DescStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("Group"), RowName, [&](const FString& Val) { NewRow.Group = Val; });
        TryApplyStringField(RowDataObject, TEXT("Command"), RowName, [&](const FString& Val) { NewRow.Command = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IgnoreNotify"), RowName, [&](bool Val) { NewRow.IgnoreNotify = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bNoGuaranteeProgressExec"), RowName, [&](bool Val) { NewRow.bNoGuaranteeProgressExec = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

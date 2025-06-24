#include "Importer/FSBActivityTableImporter.h"
#include "SBActivityTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBActivityTableImporter"

FString FSBActivityTableImporter::GetDataTableName() const
{
    return "ActivityTable";
}

TFunction<void()> FSBActivityTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBActivityTableImporter::GetRowStruct() const
{
    return FSBActivityTableProperty::StaticStruct();
}

void FSBActivityTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBActivityTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Name"), RowName, [&](const FString& Val) { NewRow.Name = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IsRequiredForCompletion"), RowName, [&](bool Val) { NewRow.IsRequiredForCompletion = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartActivityAchievement"), RowName, [&](const FString& Val) { NewRow.StartActivityAchievement = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndActivityAchievement"), RowName, [&](const FString& Val) { NewRow.EndActivityAchievement = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LinkActivities"), RowName, [&](const TArray<FString>& Val) { NewRow.LinkActivities = Val; });
        TryApplyStringField(RowDataObject, TEXT("SubCategory"), RowName, [&](const FString& Val) { NewRow.SubCategory = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayName_StringKey"), RowName, [&](const FString& Val) { NewRow.DisplayName_StringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayDescription_StringKey"), RowName, [&](const FString& Val) { NewRow.DisplayDescription_StringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayName_en_us"), RowName, [&](const FString& Val) { NewRow.DisplayName_en_us = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayDescription_en_us"), RowName, [&](const FString& Val) { NewRow.DisplayDescription_en_us = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayName_ko_kr"), RowName, [&](const FString& Val) { NewRow.DisplayName_ko_kr = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayDescription_ko_kr"), RowName, [&](const FString& Val) { NewRow.DisplayDescription_ko_kr = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

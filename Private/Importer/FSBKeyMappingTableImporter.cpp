#include "Importer/FSBKeyMappingTableImporter.h"
#include "SBKeyMappingTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBKeyMappingTableImporter"

FString FSBKeyMappingTableImporter::GetDataTableName() const
{
    return "KeyMappingTable";
}

TFunction<void()> FSBKeyMappingTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBKeyMappingTableImporter::GetRowStruct() const
{
    return FSBKeyMappingTableProperty::StaticStruct();
}

void FSBKeyMappingTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBKeyMappingTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("RecommendationStrength"), RowName, [&](const FString& Val) { NewRow.RecommendationStrength = Val; });
        TryApplyStringField(RowDataObject, TEXT("MappingGroup"), RowName, [&](const FString& Val) { NewRow.MappingGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DuplicateDenyArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DuplicateDenyArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DuplicateAllowArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DuplicateAllowArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAllowCombinationKey"), RowName, [&](bool Val) { NewRow.bAllowCombinationKey = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DuplicateCombinationKeyAllowArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DuplicateCombinationKeyAllowArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActionNames"), RowName, [&](const TArray<FString>& Val) { NewRow.ActionNames = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AxisNames"), RowName, [&](const TArray<FString>& Val) { NewRow.AxisNames = Val; });
        TryApplyStringField(RowDataObject, TEXT("AxisScaleType"), RowName, [&](const FString& Val) { NewRow.AxisScaleType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlotName"), RowName, [&](const FString& Val) { NewRow.SlotName = Val; });
        TryApplyStringField(RowDataObject, TEXT("SlotDesc"), RowName, [&](const FString& Val) { NewRow.SlotDesc = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoviePath"), RowName, [&](const FString& Val) { NewRow.MoviePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ImagePath"), RowName, [&](const FString& Val) { NewRow.ImagePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ViewerCategoryTypes"), RowName, [&](const TArray<FString>& Val) { NewRow.ViewerCategoryTypes = Val; });
        TryApplyIntField(RowDataObject, TEXT("ViewerPriority"), RowName, [&](int32 Val) { NewRow.ViewerPriority = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

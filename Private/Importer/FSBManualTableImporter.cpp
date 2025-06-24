#include "Importer/FSBManualTableImporter.h"
#include "SBManualTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBManualTableImporter"

FString FSBManualTableImporter::GetDataTableName() const
{
    return "ManualTable";
}

TFunction<void()> FSBManualTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBManualTableImporter::GetRowStruct() const
{
    return FSBManualTableProperty::StaticStruct();
}

void FSBManualTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBManualTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ManualType"), RowName, [&](const FString& Val) { NewRow.ManualType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseAcquisitionSkillString"), RowName, [&](bool Val) { NewRow.bUseAcquisitionSkillString = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupStringKey"), RowName, [&](const FString& Val) { NewRow.GroupStringKey = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DescStringKeyArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DescStringKeyArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("MoviePathArray"), RowName, [&](const TArray<FString>& Val) { NewRow.MoviePathArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ImagePathArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ImagePathArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupUnlockAchievementAlias"), RowName, [&](const FString& Val) { NewRow.GroupUnlockAchievementAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupUnlockConditionGroupAlias"), RowName, [&](const FString& Val) { NewRow.GroupUnlockConditionGroupAlias = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBRewardGroupTableImporter.h"
#include "SBRewardGroupTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBRewardGroupTableImporter"

FString FSBRewardGroupTableImporter::GetDataTableName() const
{
    return "RewardGroupTable";
}

TFunction<void()> FSBRewardGroupTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBRewardGroupTableImporter::GetRowStruct() const
{
    return FSBRewardGroupTableProperty::StaticStruct();
}

void FSBRewardGroupTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBRewardGroupTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Group"), RowName, [&](const FString& Val) { NewRow.Group = Val; });
        TryApplyStringField(RowDataObject, TEXT("GiveType"), RowName, [&](const FString& Val) { NewRow.GiveType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("MustAcquisition"), RowName, [&](bool Val) { NewRow.MustAcquisition = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupAlias"), RowName, [&](const FString& Val) { NewRow.GroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemAlias"), RowName, [&](const FString& Val) { NewRow.ItemAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemVisualAlias"), RowName, [&](const FString& Val) { NewRow.ItemVisualAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemCategory"), RowName, [&](const FString& Val) { NewRow.ItemCategory = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemCategoryTag"), RowName, [&](const FString& Val) { NewRow.ItemCategoryTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemRarity"), RowName, [&](const FString& Val) { NewRow.ItemRarity = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("DropType"), RowName, [&](const FString& Val) { NewRow.DropType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DropRateRarity"), RowName, [&](const FString& Val) { NewRow.DropRateRarity = Val; });
        TryApplyIntField(RowDataObject, TEXT("DropRate"), RowName, [&](int32 Val) { NewRow.DropRate = Val; });
        TryApplyIntField(RowDataObject, TEXT("ItemMinCount"), RowName, [&](int32 Val) { NewRow.ItemMinCount = Val; });
        TryApplyIntField(RowDataObject, TEXT("ItemMaxCount"), RowName, [&](int32 Val) { NewRow.ItemMaxCount = Val; });
        TryApplyBoolField(RowDataObject, TEXT("StatParentDependency"), RowName, [&](bool Val) { NewRow.StatParentDependency = Val; });
        TryApplyIntField(RowDataObject, TEXT("ItemStatLevelMin"), RowName, [&](int32 Val) { NewRow.ItemStatLevelMin = Val; });
        TryApplyIntField(RowDataObject, TEXT("ItemStatLevelMax"), RowName, [&](int32 Val) { NewRow.ItemStatLevelMax = Val; });
        TryApplyIntField(RowDataObject, TEXT("OverrideInteractionTime"), RowName, [&](int32 Val) { NewRow.OverrideInteractionTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardUIType"), RowName, [&](const FString& Val) { NewRow.RewardUIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBShopItemTableImporter.h"
#include "SBShopItemTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBShopItemTableImporter"

FString FSBShopItemTableImporter::GetDataTableName() const
{
    return "ShopItemTable";
}

TFunction<void()> FSBShopItemTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBShopItemTableImporter::GetRowStruct() const
{
    return FSBShopItemTableProperty::StaticStruct();
}

void FSBShopItemTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBShopItemTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShopType"), RowName, [&](const FString& Val) { NewRow.ShopType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemAlias"), RowName, [&](const FString& Val) { NewRow.ItemAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("NanosuitAliasForRecipe"), RowName, [&](const FString& Val) { NewRow.NanosuitAliasForRecipe = Val; });
        TryApplyIntField(RowDataObject, TEXT("LimitedCount"), RowName, [&](int32 Val) { NewRow.LimitedCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoneyItemAlias1"), RowName, [&](const FString& Val) { NewRow.MoneyItemAlias1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MoneyItemCount1"), RowName, [&](int32 Val) { NewRow.MoneyItemCount1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Discount_MoneyItemCount1"), RowName, [&](int32 Val) { NewRow.Discount_MoneyItemCount1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoneyItemAlias2"), RowName, [&](const FString& Val) { NewRow.MoneyItemAlias2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MoneyItemCount2"), RowName, [&](int32 Val) { NewRow.MoneyItemCount2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Discount_MoneyItemCount2"), RowName, [&](int32 Val) { NewRow.Discount_MoneyItemCount2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoneyItemAlias3"), RowName, [&](const FString& Val) { NewRow.MoneyItemAlias3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MoneyItemCount3"), RowName, [&](int32 Val) { NewRow.MoneyItemCount3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Discount_MoneyItemCount3"), RowName, [&](int32 Val) { NewRow.Discount_MoneyItemCount3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoneyItemAlias4"), RowName, [&](const FString& Val) { NewRow.MoneyItemAlias4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MoneyItemCount4"), RowName, [&](int32 Val) { NewRow.MoneyItemCount4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Discount_MoneyItemCount4"), RowName, [&](int32 Val) { NewRow.Discount_MoneyItemCount4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckAchievement"), RowName, [&](const FString& Val) { NewRow.CheckAchievement = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckCondition"), RowName, [&](const FString& Val) { NewRow.CheckCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckConditionGroup"), RowName, [&](const FString& Val) { NewRow.CheckConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("LinkedShopItemAlias"), RowName, [&](const FString& Val) { NewRow.LinkedShopItemAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("ForceDirtyRedDot"), RowName, [&](bool Val) { NewRow.ForceDirtyRedDot = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FriendShip"), RowName, [&](float Val) { NewRow.FriendShip = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

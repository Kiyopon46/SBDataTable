#include "Importer/FSBShopTableImporter.h"
#include "SBShopTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBShopTableImporter"

FString FSBShopTableImporter::GetDataTableName() const
{
    return "ShopTable";
}

TFunction<void()> FSBShopTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBShopTableImporter::GetRowStruct() const
{
    return FSBShopTableProperty::StaticStruct();
}

void FSBShopTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBShopTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyBoolField(RowDataObject, TEXT("UnionLimitedItem"), RowName, [&](bool Val) { NewRow.UnionLimitedItem = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup_ApplyDiscount"), RowName, [&](const FString& Val) { NewRow.ConditionGroup_ApplyDiscount = Val; });
        TryApplyStringField(RowDataObject, TEXT("CurrencyItemAlias"), RowName, [&](const FString& Val) { NewRow.CurrencyItemAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Tags"), RowName, [&](const TArray<FString>& Val) { NewRow.Tags = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ShopItems"), RowName, [&](const TArray<FString>& Val) { NewRow.ShopItems = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RequiredFriendShipLevelUp"), RowName, [&](const TArray<FString>& Val) { NewRow.RequiredFriendShipLevelUp = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FriendShipLevelUpSound"), RowName, [&](const TArray<FString>& Val) { NewRow.FriendShipLevelUpSound = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FriendShipLevelUpSubtitleType"), RowName, [&](const TArray<FString>& Val) { NewRow.FriendShipLevelUpSubtitleType = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FriendShipLevelUpSubtitleDuration"), RowName, [&](const TArray<FString>& Val) { NewRow.FriendShipLevelUpSubtitleDuration = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FriendShipLevelUpSubtitleTitle"), RowName, [&](const TArray<FString>& Val) { NewRow.FriendShipLevelUpSubtitleTitle = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FriendShipLevelUpSubtitleMessage"), RowName, [&](const TArray<FString>& Val) { NewRow.FriendShipLevelUpSubtitleMessage = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

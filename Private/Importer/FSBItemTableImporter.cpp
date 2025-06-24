#include "Importer/FSBItemTableImporter.h"
#include "SBItemTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemTableImporter"

FString FSBItemTableImporter::GetDataTableName() const
{
    return "ItemTable";
}

TFunction<void()> FSBItemTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemTableImporter::GetRowStruct() const
{
    return FSBItemTableProperty::StaticStruct();
}

void FSBItemTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("InventoryAlias"), RowName, [&](const FString& Val) { NewRow.InventoryAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("InventoryPriority"), RowName, [&](int32 Val) { NewRow.InventoryPriority = Val; });
        TryApplyStringField(RowDataObject, TEXT("NamePlural"), RowName, [&](const FString& Val) { NewRow.NamePlural = Val; });
        TryApplyStringField(RowDataObject, TEXT("Name"), RowName, [&](const FString& Val) { NewRow.Name = Val; });
        TryApplyStringField(RowDataObject, TEXT("Desc"), RowName, [&](const FString& Val) { NewRow.Desc = Val; });
        TryApplyStringField(RowDataObject, TEXT("DescFunction"), RowName, [&](const FString& Val) { NewRow.DescFunction = Val; });
        TryApplyStringField(RowDataObject, TEXT("DescContent"), RowName, [&](const FString& Val) { NewRow.DescContent = Val; });
        TryApplyStringField(RowDataObject, TEXT("Category"), RowName, [&](const FString& Val) { NewRow.Category = Val; });
        TryApplyStringField(RowDataObject, TEXT("CategoryTag"), RowName, [&](const FString& Val) { NewRow.CategoryTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("Rarity"), RowName, [&](const FString& Val) { NewRow.Rarity = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IncludeDropPool"), RowName, [&](bool Val) { NewRow.IncludeDropPool = Val; });
        TryApplyIntField(RowDataObject, TEXT("StackAmount"), RowName, [&](int32 Val) { NewRow.StackAmount = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxAmount"), RowName, [&](int32 Val) { NewRow.MaxAmount = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaxAmountOverrideActorStat"), RowName, [&](const FString& Val) { NewRow.MaxAmountOverrideActorStat = Val; });
        TryApplyIntField(RowDataObject, TEXT("ChargeCount"), RowName, [&](int32 Val) { NewRow.ChargeCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("ChargeOverrideActorStat"), RowName, [&](const FString& Val) { NewRow.ChargeOverrideActorStat = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AbleBroken"), RowName, [&](bool Val) { NewRow.AbleBroken = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AblePrice"), RowName, [&](bool Val) { NewRow.AblePrice = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AbleDrop"), RowName, [&](bool Val) { NewRow.AbleDrop = Val; });
        TryApplyIntField(RowDataObject, TEXT("RequireLevel"), RowName, [&](int32 Val) { NewRow.RequireLevel = Val; });
        TryApplyStringField(RowDataObject, TEXT("StudioAsset3D"), RowName, [&](const FString& Val) { NewRow.StudioAsset3D = Val; });
        TryApplyStringField(RowDataObject, TEXT("Asset3D"), RowName, [&](const FString& Val) { NewRow.Asset3D = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("Asset3DArg"), RowName, [&](const TArray<FString>& Val) { NewRow.Asset3DArg = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AssetZOffset"), RowName, [&](float Val) { NewRow.AssetZOffset = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Asset3DScale"), RowName, [&](float Val) { NewRow.Asset3DScale = Val; });
        TryApplyStringField(RowDataObject, TEXT("Asset2D"), RowName, [&](const FString& Val) { NewRow.Asset2D = Val; });
        TryApplyStringField(RowDataObject, TEXT("AlbumAsset2D"), RowName, [&](const FString& Val) { NewRow.AlbumAsset2D = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpecialRewardAsset2D"), RowName, [&](const FString& Val) { NewRow.SpecialRewardAsset2D = Val; });
        TryApplyBoolField(RowDataObject, TEXT("FastNotifySpecialReward"), RowName, [&](bool Val) { NewRow.FastNotifySpecialReward = Val; });
        TryApplyStringField(RowDataObject, TEXT("GainAllowShowPath"), RowName, [&](const FString& Val) { NewRow.GainAllowShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("AfterGainShowPath"), RowName, [&](const FString& Val) { NewRow.AfterGainShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("AfterGainShowParam"), RowName, [&](const FString& Val) { NewRow.AfterGainShowParam = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ActorBlockTime"), RowName, [&](float Val) { NewRow.ActorBlockTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("InteractionImmidateUse"), RowName, [&](bool Val) { NewRow.InteractionImmidateUse = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InteractionDist"), RowName, [&](float Val) { NewRow.InteractionDist = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AutoInteraction"), RowName, [&](bool Val) { NewRow.AutoInteraction = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AutoInteractionDist"), RowName, [&](float Val) { NewRow.AutoInteractionDist = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipableAlias"), RowName, [&](const FString& Val) { NewRow.EquipableAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConsumableAlias"), RowName, [&](const FString& Val) { NewRow.ConsumableAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillEquipableAlias"), RowName, [&](const FString& Val) { NewRow.SkillEquipableAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipmentAlias"), RowName, [&](const FString& Val) { NewRow.EquipmentAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipmentAlias2"), RowName, [&](const FString& Val) { NewRow.EquipmentAlias2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ApplyEquipType"), RowName, [&](const TArray<FString>& Val) { NewRow.ApplyEquipType = Val; });
        TryApplyStringField(RowDataObject, TEXT("BulletAlias"), RowName, [&](const FString& Val) { NewRow.BulletAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AutoCharacterLevelUpType"), RowName, [&](const FString& Val) { NewRow.AutoCharacterLevelUpType = Val; });
        TryApplyStringField(RowDataObject, TEXT("NotiType"), RowName, [&](const FString& Val) { NewRow.NotiType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ScanDisplayType"), RowName, [&](const FString& Val) { NewRow.ScanDisplayType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ScanDisplayGroup"), RowName, [&](const FString& Val) { NewRow.ScanDisplayGroup = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WeightMin"), RowName, [&](float Val) { NewRow.WeightMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WeightMax"), RowName, [&](float Val) { NewRow.WeightMax = Val; });
        TryApplyStringField(RowDataObject, TEXT("LureAlias"), RowName, [&](const FString& Val) { NewRow.LureAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMaintainNewGamePlus"), RowName, [&](bool Val) { NewRow.bMaintainNewGamePlus = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaintainMaxAmountForFirstNewGamePlus"), RowName, [&](int32 Val) { NewRow.MaintainMaxAmountForFirstNewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("ValidConditionGroup"), RowName, [&](const FString& Val) { NewRow.ValidConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

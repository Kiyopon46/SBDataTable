#include "Importer/FSBActorPlayPresetTableImporter.h"
#include "SBActorPlayPresetTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBActorPlayPresetTableImporter"

FString FSBActorPlayPresetTableImporter::GetDataTableName() const
{
    return "ActorPlayPresetTable";
}

TFunction<void()> FSBActorPlayPresetTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBActorPlayPresetTableImporter::GetRowStruct() const
{
    return FSBActorPlayPresetTableProperty::StaticStruct();
}

void FSBActorPlayPresetTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBActorPlayPresetTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("WeaponLevel"), RowName, [&](int32 Val) { NewRow.WeaponLevel = Val; });
        TryApplyIntField(RowDataObject, TEXT("BodyLevel"), RowName, [&](int32 Val) { NewRow.BodyLevel = Val; });
        TryApplyIntField(RowDataObject, TEXT("BetaLevel"), RowName, [&](int32 Val) { NewRow.BetaLevel = Val; });
        TryApplyIntField(RowDataObject, TEXT("TumblerLevel"), RowName, [&](int32 Val) { NewRow.TumblerLevel = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExoSpineLevel"), RowName, [&](int32 Val) { NewRow.ExoSpineLevel = Val; });
        TryApplyIntField(RowDataObject, TEXT("GearLevel"), RowName, [&](int32 Val) { NewRow.GearLevel = Val; });
        TryApplyStringField(RowDataObject, TEXT("PlayerDifficultyStatGroupAlias"), RowName, [&](const FString& Val) { NewRow.PlayerDifficultyStatGroupAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AcquisitionSkillList"), RowName, [&](const TArray<FString>& Val) { NewRow.AcquisitionSkillList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("PreCompleteAchievementAliasList"), RowName, [&](const TArray<FString>& Val) { NewRow.PreCompleteAchievementAliasList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("MaintainCompleteAchievementList"), RowName, [&](const TArray<FString>& Val) { NewRow.MaintainCompleteAchievementList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ItemList"), RowName, [&](const TArray<FString>& Val) { NewRow.ItemList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ItemAmountList"), RowName, [&](const TArray<FString>& Val) { NewRow.ItemAmountList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ItemLevelList"), RowName, [&](const TArray<FString>& Val) { NewRow.ItemLevelList = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Gear1"), RowName, [&](const FString& Val) { NewRow.EquipItem_Gear1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Gear2"), RowName, [&](const FString& Val) { NewRow.EquipItem_Gear2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Gear3"), RowName, [&](const FString& Val) { NewRow.EquipItem_Gear3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Gear4"), RowName, [&](const FString& Val) { NewRow.EquipItem_Gear4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_NanoSuit"), RowName, [&](const FString& Val) { NewRow.EquipItem_NanoSuit = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Protector1"), RowName, [&](const FString& Val) { NewRow.EquipItem_Protector1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Protector2"), RowName, [&](const FString& Val) { NewRow.EquipItem_Protector2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Hair1"), RowName, [&](const FString& Val) { NewRow.EquipItem_Hair1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Accessory1"), RowName, [&](const FString& Val) { NewRow.EquipItem_Accessory1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Accessory2"), RowName, [&](const FString& Val) { NewRow.EquipItem_Accessory2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EquipItem_Drone"), RowName, [&](const FString& Val) { NewRow.EquipItem_Drone = Val; });
        TryApplyIntField(RowDataObject, TEXT("Hair1_ColorIndex"), RowName, [&](int32 Val) { NewRow.Hair1_ColorIndex = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBCanTableImporter.h"
#include "SBCanTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCanTableImporter"

FString FSBCanTableImporter::GetDataTableName() const
{
    return "CanTable";
}

TFunction<void()> FSBCanTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCanTableImporter::GetRowStruct() const
{
    return FSBCanTableProperty::StaticStruct();
}

void FSBCanTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCanTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemAlias"), RowName, [&](const FString& Val) { NewRow.ItemAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringKeyTitle"), RowName, [&](const FString& Val) { NewRow.StringKeyTitle = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringKeyFunc"), RowName, [&](const FString& Val) { NewRow.StringKeyFunc = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringKeyContent"), RowName, [&](const FString& Val) { NewRow.StringKeyContent = Val; });
        TryApplyStringField(RowDataObject, TEXT("Asset3D"), RowName, [&](const FString& Val) { NewRow.Asset3D = Val; });
        TryApplyStringField(RowDataObject, TEXT("AssetMaterial"), RowName, [&](const FString& Val) { NewRow.AssetMaterial = Val; });
        TryApplyStringField(RowDataObject, TEXT("DetectEnvSpawnAlias"), RowName, [&](const FString& Val) { NewRow.DetectEnvSpawnAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AcquireEnvSpawnAlias"), RowName, [&](const FString& Val) { NewRow.AcquireEnvSpawnAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CollectionEnvSpawnAliases"), RowName, [&](const TArray<FString>& Val) { NewRow.CollectionEnvSpawnAliases = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CollectionXList"), RowName, [&](const TArray<FString>& Val) { NewRow.CollectionXList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CollectionYList"), RowName, [&](const TArray<FString>& Val) { NewRow.CollectionYList = Val; });
        TryApplyStringField(RowDataObject, TEXT("AchievementAlias"), RowName, [&](const FString& Val) { NewRow.AchievementAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideDetectDistance"), RowName, [&](float Val) { NewRow.OverrideDetectDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideAutoInteractionDistance"), RowName, [&](float Val) { NewRow.OverrideAutoInteractionDistance = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

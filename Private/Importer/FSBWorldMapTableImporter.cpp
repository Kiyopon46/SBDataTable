#include "Importer/FSBWorldMapTableImporter.h"
#include "SBWorldMapTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBWorldMapTableImporter"

FString FSBWorldMapTableImporter::GetDataTableName() const
{
    return "WorldMapTable";
}

TFunction<void()> FSBWorldMapTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBWorldMapTableImporter::GetRowStruct() const
{
    return FSBWorldMapTableProperty::StaticStruct();
}

void FSBWorldMapTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBWorldMapTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldAlias"), RowName, [&](const FString& Val) { NewRow.WorldAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("PrevWorldMapAlias"), RowName, [&](const FString& Val) { NewRow.PrevWorldMapAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextWorldMapAlias"), RowName, [&](const FString& Val) { NewRow.NextWorldMapAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExceptIsolatedAreaAlias"), RowName, [&](const FString& Val) { NewRow.ExceptIsolatedAreaAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AssetImage"), RowName, [&](const FString& Val) { NewRow.AssetImage = Val; });
        TryApplyStringField(RowDataObject, TEXT("AssetImageBG"), RowName, [&](const FString& Val) { NewRow.AssetImageBG = Val; });
        TryApplyStringField(RowDataObject, TEXT("AssetImageTitle"), RowName, [&](const FString& Val) { NewRow.AssetImageTitle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InitiaImageSize"), RowName, [&](float Val) { NewRow.InitiaImageSize = Val; });
        TryApplyIntField(RowDataObject, TEXT("InitialZoomLevel"), RowName, [&](int32 Val) { NewRow.InitialZoomLevel = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Size1"), RowName, [&](float Val) { NewRow.Size1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Speed1"), RowName, [&](float Val) { NewRow.Speed1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Size2"), RowName, [&](float Val) { NewRow.Size2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Speed2"), RowName, [&](float Val) { NewRow.Speed2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Size3"), RowName, [&](float Val) { NewRow.Size3 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Speed3"), RowName, [&](float Val) { NewRow.Speed3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("UnlockAchievementAlias"), RowName, [&](const FString& Val) { NewRow.UnlockAchievementAlias = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

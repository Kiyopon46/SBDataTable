#include "Importer/FSBZoneCampTableImporter.h"
#include "SBZoneCampTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneCampTableImporter"

FString FSBZoneCampTableImporter::GetDataTableName() const
{
    return "ZoneCampTable";
}

TFunction<void()> FSBZoneCampTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneCampTableImporter::GetRowStruct() const
{
    return FSBZoneCampTableProperty::StaticStruct();
}

void FSBZoneCampTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneCampTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampName"), RowName, [&](const FString& Val) { NewRow.CampName = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampType"), RowName, [&](const FString& Val) { NewRow.CampType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Region"), RowName, [&](const FString& Val) { NewRow.Region = Val; });
        TryApplyStringField(RowDataObject, TEXT("RegionName"), RowName, [&](const FString& Val) { NewRow.RegionName = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampImage"), RowName, [&](const FString& Val) { NewRow.CampImage = Val; });
        TryApplyStringField(RowDataObject, TEXT("InGameUICampImage"), RowName, [&](const FString& Val) { NewRow.InGameUICampImage = Val; });
        TryApplyStringField(RowDataObject, TEXT("CoinSpawnPointName"), RowName, [&](const FString& Val) { NewRow.CoinSpawnPointName = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideCampDetectDistance_Max"), RowName, [&](float Val) { NewRow.OverrideCampDetectDistance_Max = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampDisplayType"), RowName, [&](const FString& Val) { NewRow.CampDisplayType = Val; });
        TryApplyStringField(RowDataObject, TEXT("LinkCampAlias"), RowName, [&](const FString& Val) { NewRow.LinkCampAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CampDisplayLinkAlias"), RowName, [&](const FString& Val) { NewRow.CampDisplayLinkAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveTag"), RowName, [&](const FString& Val) { NewRow.ActiveTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnableMapMakerCondition"), RowName, [&](const FString& Val) { NewRow.EnableMapMakerCondition = Val; });
        TryApplyFloatField(RowDataObject, TEXT("WorldMapOverlapDistance"), RowName, [&](float Val) { NewRow.WorldMapOverlapDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("ForceCampTrophyAchievementForEnvState"), RowName, [&](const FString& Val) { NewRow.ForceCampTrophyAchievementForEnvState = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

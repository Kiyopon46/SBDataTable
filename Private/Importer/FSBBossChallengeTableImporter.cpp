#include "Importer/FSBBossChallengeTableImporter.h"
#include "SBBossChallengeTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBBossChallengeTableImporter"

FSBMenuEntry FSBBossChallengeTableImporter::GetMenuEntry()
{
    FSBMenuEntry Entry;
    Entry.Name = "BossChallengeTableEntry";
    Entry.Label = LOCTEXT("BossChallengeTableEntry", "BossChallengeTable");
    Entry.Tooltip = LOCTEXT("BossChallengeTableEntry_Tooltip", "Run BossChallengeTable tool");

    Entry.Callback = [this]()
    {
        this->Execute();
    };

    return Entry;
}

FString FSBBossChallengeTableImporter::GetPackagePath() const
{
    return TEXT("/Game/Local/Data/BossChallengeTable");
}

UScriptStruct* FSBBossChallengeTableImporter::GetRowStruct() const
{
    return FSBBossChallengeTableProperty::StaticStruct();
}

void FSBBossChallengeTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject)
{
    for (const auto& RowPair : RowsObject->Values) {
        FString RowName = RowPair.Key;

        const TSharedPtr<FJsonObject>* RowDataObjectPtr;
        if (!RowPair.Value->TryGetObject(RowDataObjectPtr) || !RowDataObjectPtr) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid row object for RowName: %s"), *RowName);
            continue;
        }

        const TSharedPtr<FJsonObject>& RowDataObject = *RowDataObjectPtr;

        FSBBossChallengeTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("StageGroup"), RowName, [&](const FString& Val) { NewRow.StageGroup = Val; });
        TryApplyIntField(RowDataObject, TEXT("StagePriority"), RowName, [&](int32 Val) { NewRow.StagePriority = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneAlias"), RowName, [&](const FString& Val) { NewRow.ZoneAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpawnPointAlias"), RowName, [&](const FString& Val) { NewRow.SpawnPointAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UnlockAchievementArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UnlockAchievementArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UnlockEntitlementArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UnlockEntitlementArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnemyEventSpawnList"), RowName, [&](const TArray<FString>& Val) { NewRow.EnemyEventSpawnList = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaximumPresetAlias"), RowName, [&](const FString& Val) { NewRow.MaximumPresetAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaximumNewGamePlusPresetAlias"), RowName, [&](const FString& Val) { NewRow.MaximumNewGamePlusPresetAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("MinimumPresetAlias"), RowName, [&](const FString& Val) { NewRow.MinimumPresetAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaximumPresetAliasStoryMode"), RowName, [&](const FString& Val) { NewRow.MaximumPresetAliasStoryMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaximumNewGamePlusPresetAliasStoryMode"), RowName, [&](const FString& Val) { NewRow.MaximumNewGamePlusPresetAliasStoryMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("MinimumPresetAliasStoryMode"), RowName, [&](const FString& Val) { NewRow.MinimumPresetAliasStoryMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaximumPresetAliasHardMode"), RowName, [&](const FString& Val) { NewRow.MaximumPresetAliasHardMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaximumNewGamePlusPresetAliasHardMode"), RowName, [&](const FString& Val) { NewRow.MaximumNewGamePlusPresetAliasHardMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("MinimumPresetAliasHardMode"), RowName, [&](const FString& Val) { NewRow.MinimumPresetAliasHardMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("BossStringKey"), RowName, [&](const FString& Val) { NewRow.BossStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("RegionStringKey"), RowName, [&](const FString& Val) { NewRow.RegionStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ThumbnailImagePath"), RowName, [&](const FString& Val) { NewRow.ThumbnailImagePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ThumbnailIconImagePath"), RowName, [&](const FString& Val) { NewRow.ThumbnailIconImagePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ResourceCacheCharacterAliases"), RowName, [&](const TArray<FString>& Val) { NewRow.ResourceCacheCharacterAliases = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

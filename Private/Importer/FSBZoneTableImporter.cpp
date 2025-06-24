#include "Importer/FSBZoneTableImporter.h"
#include "SBZoneTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneTableImporter"

FString FSBZoneTableImporter::GetDataTableName() const
{
    return "ZoneTable";
}

TFunction<void()> FSBZoneTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneTableImporter::GetRowStruct() const
{
    return FSBZoneTableProperty::StaticStruct();
}

void FSBZoneTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("WorldAlias"), RowName, [&](const FString& Val) { NewRow.WorldAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("IsolatedAreaAlias"), RowName, [&](const FString& Val) { NewRow.IsolatedAreaAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bOverrideIsolatedAreaWithWorldMap"), RowName, [&](bool Val) { NewRow.bOverrideIsolatedAreaWithWorldMap = Val; });
        TryApplyStringField(RowDataObject, TEXT("ZoneType"), RowName, [&](const FString& Val) { NewRow.ZoneType = Val; });
        TryApplyStringField(RowDataObject, TEXT("NpcTransitType"), RowName, [&](const FString& Val) { NewRow.NpcTransitType = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitActive"), RowName, [&](const FString& Val) { NewRow.InitActive = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrainningRoom"), RowName, [&](const FString& Val) { NewRow.TrainningRoom = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartPointAlias"), RowName, [&](const FString& Val) { NewRow.StartPointAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnterZoneResetLayerList"), RowName, [&](const TArray<FString>& Val) { NewRow.EnterZoneResetLayerList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LeaveZoneResetLayerList"), RowName, [&](const TArray<FString>& Val) { NewRow.LeaveZoneResetLayerList = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnterEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.EnterEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LeaveEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.LeaveEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ActiveEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.ActiveEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeactiveEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.DeactiveEvents = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ZoneSpawnEvents"), RowName, [&](const TArray<FString>& Val) { NewRow.ZoneSpawnEvents = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnterZoneEffectTargetType"), RowName, [&](const FString& Val) { NewRow.EnterZoneEffectTargetType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnterZoneEffectAtLeaveState"), RowName, [&](const FString& Val) { NewRow.EnterZoneEffectAtLeaveState = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnterZoneEffects"), RowName, [&](const TArray<FString>& Val) { NewRow.EnterZoneEffects = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TransitAchievement"), RowName, [&](const TArray<FString>& Val) { NewRow.TransitAchievement = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TransitZone"), RowName, [&](const TArray<FString>& Val) { NewRow.TransitZone = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("LoadLevels"), RowName, [&](const TArray<FString>& Val) { NewRow.LoadLevels = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UnloadLevels"), RowName, [&](const TArray<FString>& Val) { NewRow.UnloadLevels = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bRestoreLevelWhenLeave"), RowName, [&](bool Val) { NewRow.bRestoreLevelWhenLeave = Val; });
        TryApplyStringField(RowDataObject, TEXT("PlayRule"), RowName, [&](const FString& Val) { NewRow.PlayRule = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpiritRoomEscapeCondition"), RowName, [&](const FString& Val) { NewRow.SpiritRoomEscapeCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("SpiritRoomEscapeConditionGroup"), RowName, [&](const FString& Val) { NewRow.SpiritRoomEscapeConditionGroup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSpiritRoom_ChoiceOpenPopup"), RowName, [&](bool Val) { NewRow.bSpiritRoom_ChoiceOpenPopup = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelGraphicsOptionsAlias"), RowName, [&](const FString& Val) { NewRow.LevelGraphicsOptionsAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideEnterZoneFadeInDelayTime"), RowName, [&](float Val) { NewRow.OverrideEnterZoneFadeInDelayTime = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AdditiveDesignLevel"), RowName, [&](const TArray<FString>& Val) { NewRow.AdditiveDesignLevel = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

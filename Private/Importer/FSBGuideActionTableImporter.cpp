#include "Importer/FSBGuideActionTableImporter.h"
#include "SBGuideActionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBGuideActionTableImporter"

FString FSBGuideActionTableImporter::GetDataTableName() const
{
    return "GuideActionTable";
}

TFunction<void()> FSBGuideActionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBGuideActionTableImporter::GetRowStruct() const
{
    return FSBGuideActionTableProperty::StaticStruct();
}

void FSBGuideActionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBGuideActionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("PathWayName"), RowName, [&](const FString& Val) { NewRow.PathWayName = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ZoneEventsWhenStart"), RowName, [&](const TArray<FString>& Val) { NewRow.ZoneEventsWhenStart = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ZoneEventsWhenArrive"), RowName, [&](const TArray<FString>& Val) { NewRow.ZoneEventsWhenArrive = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ZoneEventsWhenComplete"), RowName, [&](const TArray<FString>& Val) { NewRow.ZoneEventsWhenComplete = Val; });
        TryApplyStringField(RowDataObject, TEXT("TheaterWhenStart"), RowName, [&](const FString& Val) { NewRow.TheaterWhenStart = Val; });
        TryApplyStringField(RowDataObject, TEXT("TheaterWhenArrive"), RowName, [&](const FString& Val) { NewRow.TheaterWhenArrive = Val; });
        TryApplyStringField(RowDataObject, TEXT("TheaterWhenComplete"), RowName, [&](const FString& Val) { NewRow.TheaterWhenComplete = Val; });
        TryApplyStringField(RowDataObject, TEXT("TheaterWhenMovePause"), RowName, [&](const FString& Val) { NewRow.TheaterWhenMovePause = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceWhenStart"), RowName, [&](const FString& Val) { NewRow.LevelSequenceWhenStart = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceWhenArrive"), RowName, [&](const FString& Val) { NewRow.LevelSequenceWhenArrive = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceWhenComplete"), RowName, [&](const FString& Val) { NewRow.LevelSequenceWhenComplete = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSequenceWhenMovePause"), RowName, [&](const FString& Val) { NewRow.LevelSequenceWhenMovePause = Val; });
        TryApplyStringField(RowDataObject, TEXT("QuestTaskGroupAlias"), RowName, [&](const FString& Val) { NewRow.QuestTaskGroupAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bPlayerAggroCheck"), RowName, [&](bool Val) { NewRow.bPlayerAggroCheck = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bPlayerMoveControl"), RowName, [&](bool Val) { NewRow.bPlayerMoveControl = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PlayerMoveAreaLimitDistance"), RowName, [&](float Val) { NewRow.PlayerMoveAreaLimitDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PlayerRunLimitDistance"), RowName, [&](float Val) { NewRow.PlayerRunLimitDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PlayerSprintLimitDistance"), RowName, [&](float Val) { NewRow.PlayerSprintLimitDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMoveStateControlByPlayer"), RowName, [&](bool Val) { NewRow.bMoveStateControlByPlayer = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveStateFromForwardPlayer"), RowName, [&](const FString& Val) { NewRow.MoveStateFromForwardPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinDistanceFromForwardPlayer"), RowName, [&](float Val) { NewRow.MinDistanceFromForwardPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxDistanceFromForwardPlayer"), RowName, [&](float Val) { NewRow.MaxDistanceFromForwardPlayer = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveStateFromBackwardPlayer"), RowName, [&](const FString& Val) { NewRow.MoveStateFromBackwardPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinDistanceFromBackwardPlayer"), RowName, [&](float Val) { NewRow.MinDistanceFromBackwardPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxDistanceFromBackwardPlayer"), RowName, [&](float Val) { NewRow.MaxDistanceFromBackwardPlayer = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bFixedTargetRotation"), RowName, [&](bool Val) { NewRow.bFixedTargetRotation = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StopDistanceToPlayer"), RowName, [&](float Val) { NewRow.StopDistanceToPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MovePauseDistanceToPlayer"), RowName, [&](float Val) { NewRow.MovePauseDistanceToPlayer = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMovePauseLookAtPlayer"), RowName, [&](bool Val) { NewRow.bMovePauseLookAtPlayer = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovePauseShow"), RowName, [&](const FString& Val) { NewRow.MovePauseShow = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLoopMovePauseShow"), RowName, [&](bool Val) { NewRow.bLoopMovePauseShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveResumeDistanceToPlayer"), RowName, [&](float Val) { NewRow.MoveResumeDistanceToPlayer = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartShow"), RowName, [&](const FString& Val) { NewRow.StartShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartShowDelayTime"), RowName, [&](float Val) { NewRow.StartShowDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("ArriveShow"), RowName, [&](const FString& Val) { NewRow.ArriveShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ArriveShowDelayTime"), RowName, [&](float Val) { NewRow.ArriveShowDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLoopArriveShow"), RowName, [&](bool Val) { NewRow.bLoopArriveShow = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLookAtPlayerWhenArrive"), RowName, [&](bool Val) { NewRow.bLookAtPlayerWhenArrive = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverrideMaxSpeed"), RowName, [&](float Val) { NewRow.OverrideMaxSpeed = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCompleteLookAtPlayer"), RowName, [&](bool Val) { NewRow.bCompleteLookAtPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CompleteWaitTime"), RowName, [&](float Val) { NewRow.CompleteWaitTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveDelayTime"), RowName, [&](float Val) { NewRow.MoveDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("StanceAlias"), RowName, [&](const FString& Val) { NewRow.StanceAlias = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUsePathfinding"), RowName, [&](bool Val) { NewRow.bUsePathfinding = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CompletedTimerWhenArrive"), RowName, [&](float Val) { NewRow.CompletedTimerWhenArrive = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CompletedDistanceToPlayerWhenArrive"), RowName, [&](float Val) { NewRow.CompletedDistanceToPlayerWhenArrive = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bFly"), RowName, [&](bool Val) { NewRow.bFly = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FlyMoveSpeedPow"), RowName, [&](float Val) { NewRow.FlyMoveSpeedPow = Val; });
        TryApplyStringField(RowDataObject, TEXT("FormationType"), RowName, [&](const FString& Val) { NewRow.FormationType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableDroneUIIndicator"), RowName, [&](bool Val) { NewRow.bDisableDroneUIIndicator = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

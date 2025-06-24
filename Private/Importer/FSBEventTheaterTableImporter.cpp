#include "Importer/FSBEventTheaterTableImporter.h"
#include "SBZoneEventTheaterTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventTheaterTableImporter"

FString FSBEventTheaterTableImporter::GetDataTableName() const
{
    return "EventTheaterTable";
}

TFunction<void()> FSBEventTheaterTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventTheaterTableImporter::GetRowStruct() const
{
    return FSBZoneEventTheaterTableProperty::StaticStruct();
}

void FSBEventTheaterTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventTheaterTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TheaterAlias"), RowName, [&](const FString& Val) { NewRow.TheaterAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("TheaterAssetPath"), RowName, [&](const FString& Val) { NewRow.TheaterAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("LevelSeqAssetPath"), RowName, [&](const FString& Val) { NewRow.LevelSeqAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ControlType"), RowName, [&](const FString& Val) { NewRow.ControlType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SequencePlayTransformType"), RowName, [&](const FString& Val) { NewRow.SequencePlayTransformType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SequencePlayTransformCastType"), RowName, [&](const FString& Val) { NewRow.SequencePlayTransformCastType = Val; });
        TryApplyStringField(RowDataObject, TEXT("BindTargetType"), RowName, [&](const FString& Val) { NewRow.BindTargetType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BindTargetStartFadeOutKeepDuration"), RowName, [&](float Val) { NewRow.BindTargetStartFadeOutKeepDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("BindTargetStartFadeInDuration"), RowName, [&](float Val) { NewRow.BindTargetStartFadeInDuration = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSkipFadeOutAtBindTargeType"), RowName, [&](bool Val) { NewRow.bSkipFadeOutAtBindTargeType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventSpawnAlias"), RowName, [&](const FString& Val) { NewRow.EventSpawnAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("BindZoneEnvAlias"), RowName, [&](const TArray<FString>& Val) { NewRow.BindZoneEnvAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("TheaterSelectDataList"), RowName, [&](const TArray<FString>& Val) { NewRow.TheaterSelectDataList = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSkipAlreadyPlaySameTheater"), RowName, [&](bool Val) { NewRow.bSkipAlreadyPlaySameTheater = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseStartFadeInScreenForLeveStream"), RowName, [&](bool Val) { NewRow.bUseStartFadeInScreenForLeveStream = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartFadeInDuration"), RowName, [&](float Val) { NewRow.StartFadeInDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StartFadeInTime"), RowName, [&](float Val) { NewRow.StartFadeInTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bFirstTimeIntro"), RowName, [&](bool Val) { NewRow.bFirstTimeIntro = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseEndFadeInScreenForLeveStream"), RowName, [&](bool Val) { NewRow.bUseEndFadeInScreenForLeveStream = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingApplyType1"), RowName, [&](const FString& Val) { NewRow.MeshClipingApplyType1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingLocation1"), RowName, [&](const FString& Val) { NewRow.MeshClipingLocation1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingRotation1"), RowName, [&](const FString& Val) { NewRow.MeshClipingRotation1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingScale1"), RowName, [&](const FString& Val) { NewRow.MeshClipingScale1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingApplyType2"), RowName, [&](const FString& Val) { NewRow.MeshClipingApplyType2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingLocation2"), RowName, [&](const FString& Val) { NewRow.MeshClipingLocation2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingRotation2"), RowName, [&](const FString& Val) { NewRow.MeshClipingRotation2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MeshClipingScale2"), RowName, [&](const FString& Val) { NewRow.MeshClipingScale2 = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCancelWhenPlayerWarp"), RowName, [&](bool Val) { NewRow.bCancelWhenPlayerWarp = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBlockInputByBindSequence"), RowName, [&](bool Val) { NewRow.bBlockInputByBindSequence = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

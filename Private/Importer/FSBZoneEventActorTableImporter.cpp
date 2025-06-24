#include "Importer/FSBZoneEventActorTableImporter.h"
#include "SBZoneEventActorTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBZoneEventActorTableImporter"

FString FSBZoneEventActorTableImporter::GetDataTableName() const
{
    return "ZoneEventActorTable";
}

TFunction<void()> FSBZoneEventActorTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBZoneEventActorTableImporter::GetRowStruct() const
{
    return FSBZoneEventActorTableProperty::StaticStruct();
}

void FSBZoneEventActorTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventActorTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bCollisionHitToActor"), RowName, [&](bool Val) { NewRow.bCollisionHitToActor = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CollisionActorDistance"), RowName, [&](float Val) { NewRow.CollisionActorDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomEffectValue"), RowName, [&](const FString& Val) { NewRow.CustomEffectValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomEffectValueByFireElement"), RowName, [&](const FString& Val) { NewRow.CustomEffectValueByFireElement = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EventInterval"), RowName, [&](float Val) { NewRow.EventInterval = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DespawnDelayTime"), RowName, [&](float Val) { NewRow.DespawnDelayTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetFilterExtentX"), RowName, [&](float Val) { NewRow.TargetFilterExtentX = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetFilterExtentY"), RowName, [&](float Val) { NewRow.TargetFilterExtentY = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetFilterCheckHeight"), RowName, [&](float Val) { NewRow.TargetFilterCheckHeight = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ScaleTickDistance"), RowName, [&](float Val) { NewRow.ScaleTickDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardSpawnFormationAsset"), RowName, [&](const FString& Val) { NewRow.RewardSpawnFormationAsset = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DestructionEvent_DelayMinTime"), RowName, [&](float Val) { NewRow.DestructionEvent_DelayMinTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DestructionEvent_DelayMaxTime"), RowName, [&](float Val) { NewRow.DestructionEvent_DelayMaxTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestructionEvent_EffectAlias"), RowName, [&](const FString& Val) { NewRow.DestructionEvent_EffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestructionEvent_RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.DestructionEvent_RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestructionEvent_RewardBucketType"), RowName, [&](const FString& Val) { NewRow.DestructionEvent_RewardBucketType = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestructionEvent_RewardOverrideSaveType"), RowName, [&](const FString& Val) { NewRow.DestructionEvent_RewardOverrideSaveType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DestructionEvent_RewardRemoveItemWithResetZone"), RowName, [&](bool Val) { NewRow.DestructionEvent_RewardRemoveItemWithResetZone = Val; });
        TryApplyStringField(RowDataObject, TEXT("DestructionEvent_ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.DestructionEvent_ZoneEventAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DestructionEvent_ZoneEventAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DestructionEvent_ZoneEventAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DestructionEvent_EffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DestructionEvent_EffectAliasArray = Val; });
        TryApplyIntField(RowDataObject, TEXT("DestructCountMax"), RowName, [&](int32 Val) { NewRow.DestructCountMax = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DestructionTimer"), RowName, [&](float Val) { NewRow.DestructionTimer = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CountEventStepArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CountEventStepArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CountEventRewardGroupAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CountEventRewardGroupAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CountEventRewardBucketTypeArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CountEventRewardBucketTypeArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CountEventEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CountEventEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CountEventZoneEventAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CountEventZoneEventAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent1_RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent1_RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent1_EffectAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent1_EffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent1_ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent1_ZoneEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent2_RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent2_RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent2_EffectAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent2_EffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent2_ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent2_ZoneEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent3_RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent3_RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent3_EffectAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent3_EffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent3_ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent3_ZoneEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent4_RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent4_RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent4_EffectAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent4_EffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent4_ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent4_ZoneEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent5_RewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent5_RewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent5_EffectAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent5_EffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("CountEvent5_ZoneEventAlias"), RowName, [&](const FString& Val) { NewRow.CountEvent5_ZoneEventAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

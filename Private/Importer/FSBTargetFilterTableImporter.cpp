#include "Importer/FSBTargetFilterTableImporter.h"
#include "SBSkillTargetFilterTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBTargetFilterTableImporter"

FString FSBTargetFilterTableImporter::GetDataTableName() const
{
    return "TargetFilterTable";
}

TFunction<void()> FSBTargetFilterTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBTargetFilterTableImporter::GetRowStruct() const
{
    return FSBSkillTargetFilterTableProperty::StaticStruct();
}

void FSBTargetFilterTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSkillTargetFilterTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetType"), RowName, [&](const FString& Val) { NewRow.TargetType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMultipleTargets"), RowName, [&](bool Val) { NewRow.bMultipleTargets = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDynamicShapeScale"), RowName, [&](bool Val) { NewRow.bDynamicShapeScale = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinShapeScale"), RowName, [&](float Val) { NewRow.MinShapeScale = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxShapeScale"), RowName, [&](float Val) { NewRow.MaxShapeScale = Val; });
        TryApplyFloatField(RowDataObject, TEXT("NearDistance"), RowName, [&](float Val) { NewRow.NearDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FarDistance"), RowName, [&](float Val) { NewRow.FarDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("SortType"), RowName, [&](const FString& Val) { NewRow.SortType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckHitStepTimeWhenSortParry"), RowName, [&](float Val) { NewRow.CheckHitStepTimeWhenSortParry = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShapeForwardDistance"), RowName, [&](float Val) { NewRow.ShapeForwardDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShapeRightDistance"), RowName, [&](float Val) { NewRow.ShapeRightDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ShapeUpDistance"), RowName, [&](float Val) { NewRow.ShapeUpDistance = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetCheckShape"), RowName, [&](const FString& Val) { NewRow.TargetCheckShape = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetCheckValue1"), RowName, [&](float Val) { NewRow.TargetCheckValue1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetCheckValue2"), RowName, [&](float Val) { NewRow.TargetCheckValue2 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetCheckValue3"), RowName, [&](float Val) { NewRow.TargetCheckValue3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState1"), RowName, [&](const FString& Val) { NewRow.ActorState1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState2"), RowName, [&](const FString& Val) { NewRow.ActorState2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState3"), RowName, [&](const FString& Val) { NewRow.ActorState3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState4"), RowName, [&](const FString& Val) { NewRow.ActorState4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorState5"), RowName, [&](const FString& Val) { NewRow.ActorState5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("NonActorState1"), RowName, [&](const FString& Val) { NewRow.NonActorState1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("NonActorState2"), RowName, [&](const FString& Val) { NewRow.NonActorState2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("NonActorState3"), RowName, [&](const FString& Val) { NewRow.NonActorState3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("NonActorState4"), RowName, [&](const FString& Val) { NewRow.NonActorState4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("NonActorState5"), RowName, [&](const FString& Val) { NewRow.NonActorState5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorStat1"), RowName, [&](const FString& Val) { NewRow.ActorStat1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorStatCheck1"), RowName, [&](const FString& Val) { NewRow.ActorStatCheck1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ActorStatCheckValue1"), RowName, [&](int32 Val) { NewRow.ActorStatCheckValue1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckMinAngleToTarget"), RowName, [&](float Val) { NewRow.CheckMinAngleToTarget = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckMaxAngleToTarget"), RowName, [&](float Val) { NewRow.CheckMaxAngleToTarget = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bDisableBlockingCheck"), RowName, [&](bool Val) { NewRow.bDisableBlockingCheck = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBlockingCheckWithTopLocation"), RowName, [&](bool Val) { NewRow.bBlockingCheckWithTopLocation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bValidEngineHandle"), RowName, [&](bool Val) { NewRow.bValidEngineHandle = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckBattleMode"), RowName, [&](const FString& Val) { NewRow.CheckBattleMode = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckActiveEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckActiveEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckActiveNoneEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckActiveNoneEffectAliasArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckActiveEffectAliasArrayWhenEasyMode"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckActiveEffectAliasArrayWhenEasyMode = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckActiveNoneEffectAliasArrayWhenEasyMode"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckActiveNoneEffectAliasArrayWhenEasyMode = Val; });
        TryApplyFloatField(RowDataObject, TEXT("GroundHeightToTarget"), RowName, [&](float Val) { NewRow.GroundHeightToTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("bSwimming"), RowName, [&](const FString& Val) { NewRow.bSwimming = Val; });
        TryApplyStringField(RowDataObject, TEXT("bEncroachmentable"), RowName, [&](const FString& Val) { NewRow.bEncroachmentable = Val; });
        TryApplyStringField(RowDataObject, TEXT("bDead"), RowName, [&](const FString& Val) { NewRow.bDead = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bNotSupportedZoneEventActor"), RowName, [&](bool Val) { NewRow.bNotSupportedZoneEventActor = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

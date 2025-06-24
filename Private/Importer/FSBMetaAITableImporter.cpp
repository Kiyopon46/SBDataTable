#include "Importer/FSBMetaAITableImporter.h"
#include "SBMetaAITableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBMetaAITableImporter"

FString FSBMetaAITableImporter::GetDataTableName() const
{
    return "MetaAITable";
}

TFunction<void()> FSBMetaAITableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBMetaAITableImporter::GetRowStruct() const
{
    return FSBMetaAITableProperty::StaticStruct();
}

void FSBMetaAITableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBMetaAITableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Job"), RowName, [&](const FString& Val) { NewRow.Job = Val; });
        TryApplyStringField(RowDataObject, TEXT("Appearance"), RowName, [&](const FString& Val) { NewRow.Appearance = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("InitTagArray"), RowName, [&](const TArray<FString>& Val) { NewRow.InitTagArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ValidThinkArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ValidThinkArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("BehaviorAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.BehaviorAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepNodeGroupIndex"), RowName, [&](bool Val) { NewRow.bKeepNodeGroupIndex = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableCollisionOverlap"), RowName, [&](bool Val) { NewRow.bEnableCollisionOverlap = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundIntervalTime"), RowName, [&](float Val) { NewRow.MoveAroundIntervalTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundProbability"), RowName, [&](float Val) { NewRow.MoveAroundProbability = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseOnlyTagNode"), RowName, [&](bool Val) { NewRow.bUseOnlyTagNode = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLookAtOnly"), RowName, [&](bool Val) { NewRow.bLookAtOnly = Val; });
        TryApplyStringField(RowDataObject, TEXT("LookAtType"), RowName, [&](const FString& Val) { NewRow.LookAtType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtYawAngle"), RowName, [&](float Val) { NewRow.LookAtYawAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtPitchAngle"), RowName, [&](float Val) { NewRow.LookAtPitchAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtOnceTime"), RowName, [&](float Val) { NewRow.LookAtOnceTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtCooltime"), RowName, [&](float Val) { NewRow.LookAtCooltime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtDistance"), RowName, [&](float Val) { NewRow.LookAtDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LookAtStopDistance"), RowName, [&](float Val) { NewRow.LookAtStopDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StopMoveDistanceWithPlayer"), RowName, [&](float Val) { NewRow.StopMoveDistanceWithPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StopMoveAngleWithPlayer"), RowName, [&](float Val) { NewRow.StopMoveAngleWithPlayer = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StopMoveOnceTime"), RowName, [&](float Val) { NewRow.StopMoveOnceTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StopMoveCoolTime"), RowName, [&](float Val) { NewRow.StopMoveCoolTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableShoulderCharge"), RowName, [&](bool Val) { NewRow.bEnableShoulderCharge = Val; });
        TryApplyStringField(RowDataObject, TEXT("ShoulderChargeShowPath"), RowName, [&](const FString& Val) { NewRow.ShoulderChargeShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehaviorCheckTime"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehaviorCheckTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehaviorActivationRate"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehaviorActivationRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAroundCustomBehavior1_ShowPath"), RowName, [&](const FString& Val) { NewRow.MoveAroundCustomBehavior1_ShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehavior1_ActivationRate"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehavior1_ActivationRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAroundCustomBehavior2_ShowPath"), RowName, [&](const FString& Val) { NewRow.MoveAroundCustomBehavior2_ShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehavior2_ActivationRate"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehavior2_ActivationRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAroundCustomBehavior3_ShowPath"), RowName, [&](const FString& Val) { NewRow.MoveAroundCustomBehavior3_ShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehavior3_ActivationRate"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehavior3_ActivationRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAroundCustomBehavior4_ShowPath"), RowName, [&](const FString& Val) { NewRow.MoveAroundCustomBehavior4_ShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehavior4_ActivationRate"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehavior4_ActivationRate = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAroundCustomBehavior5_ShowPath"), RowName, [&](const FString& Val) { NewRow.MoveAroundCustomBehavior5_ShowPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MoveAroundCustomBehavior5_ActivationRate"), RowName, [&](float Val) { NewRow.MoveAroundCustomBehavior5_ActivationRate = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bInitZeroTiredness"), RowName, [&](bool Val) { NewRow.bInitZeroTiredness = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

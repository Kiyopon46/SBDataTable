#include "Importer/FSBItemFishTableImporter.h"
#include "SBItemFishTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBItemFishTableImporter"

FString FSBItemFishTableImporter::GetDataTableName() const
{
    return "ItemFishTable";
}

TFunction<void()> FSBItemFishTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBItemFishTableImporter::GetRowStruct() const
{
    return FSBItemFishTableProperty::StaticStruct();
}

void FSBItemFishTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBItemFishTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishRarity"), RowName, [&](const FString& Val) { NewRow.FishRarity = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bNikke"), RowName, [&](bool Val) { NewRow.bNikke = Val; });
        TryApplyIntField(RowDataObject, TEXT("Stamina"), RowName, [&](int32 Val) { NewRow.Stamina = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RunAwayStaminaRate"), RowName, [&](const TArray<FString>& Val) { NewRow.RunAwayStaminaRate = Val; });
        TryApplyIntField(RowDataObject, TEXT("RunAwayDistance"), RowName, [&](int32 Val) { NewRow.RunAwayDistance = Val; });
        TryApplyIntField(RowDataObject, TEXT("PullSpeed"), RowName, [&](int32 Val) { NewRow.PullSpeed = Val; });
        TryApplyFloatField(RowDataObject, TEXT("PullHitAreaSize"), RowName, [&](float Val) { NewRow.PullHitAreaSize = Val; });
        TryApplyIntField(RowDataObject, TEXT("FightingTime"), RowName, [&](int32 Val) { NewRow.FightingTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("LiftUpBobberScale"), RowName, [&](float Val) { NewRow.LiftUpBobberScale = Val; });
        TryApplyStringField(RowDataObject, TEXT("LiftUpCamStartLocation"), RowName, [&](const FString& Val) { NewRow.LiftUpCamStartLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("LiftUpCamFinalLocation"), RowName, [&](const FString& Val) { NewRow.LiftUpCamFinalLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishFinalLocation"), RowName, [&](const FString& Val) { NewRow.FishFinalLocation = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroup"), RowName, [&](const FString& Val) { NewRow.ConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionRewardGroup"), RowName, [&](const FString& Val) { NewRow.ConditionRewardGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardGroup"), RowName, [&](const FString& Val) { NewRow.RewardGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("RewardItemAlias"), RowName, [&](const FString& Val) { NewRow.RewardItemAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("RewardItemCount"), RowName, [&](int32 Val) { NewRow.RewardItemCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovePatternCurveDataPath1"), RowName, [&](const FString& Val) { NewRow.MovePatternCurveDataPath1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MovePatternWeight1"), RowName, [&](int32 Val) { NewRow.MovePatternWeight1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovePatternCurveDataPath2"), RowName, [&](const FString& Val) { NewRow.MovePatternCurveDataPath2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MovePatternWeight2"), RowName, [&](int32 Val) { NewRow.MovePatternWeight2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovePatternCurveDataPath3"), RowName, [&](const FString& Val) { NewRow.MovePatternCurveDataPath3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MovePatternWeight3"), RowName, [&](int32 Val) { NewRow.MovePatternWeight3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovePatternCurveDataPath4"), RowName, [&](const FString& Val) { NewRow.MovePatternCurveDataPath4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MovePatternWeight4"), RowName, [&](int32 Val) { NewRow.MovePatternWeight4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("MovePatternCurveDataPath5"), RowName, [&](const FString& Val) { NewRow.MovePatternCurveDataPath5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("MovePatternWeight5"), RowName, [&](int32 Val) { NewRow.MovePatternWeight5 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TimingPullArrowSpeed"), RowName, [&](float Val) { NewRow.TimingPullArrowSpeed = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullGaugeReductionPerHit"), RowName, [&](int32 Val) { NewRow.TimingPullGaugeReductionPerHit = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaStart1"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaStart1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaSize1"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaSize1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaStart2"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaStart2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaSize2"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaSize2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaStart3"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaStart3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaSize3"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaSize3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaStart4"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaStart4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaSize4"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaSize4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaStart5"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaStart5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("TimingPullHitAreaSize5"), RowName, [&](int32 Val) { NewRow.TimingPullHitAreaSize5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

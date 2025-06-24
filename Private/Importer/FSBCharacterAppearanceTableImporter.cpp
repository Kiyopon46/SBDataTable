#include "Importer/FSBCharacterAppearanceTableImporter.h"
#include "SBCharacterAppearanceTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterAppearanceTableImporter"

FString FSBCharacterAppearanceTableImporter::GetDataTableName() const
{
    return "CharacterAppearanceTable";
}

TFunction<void()> FSBCharacterAppearanceTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterAppearanceTableImporter::GetRowStruct() const
{
    return FSBCharacterAppearanceTableProperty::StaticStruct();
}

void FSBCharacterAppearanceTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterAppearanceTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("CharacterAssetPath"), RowName, [&](const FString& Val) { NewRow.CharacterAssetPath = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CapsuleRadius"), RowName, [&](float Val) { NewRow.CapsuleRadius = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CapsuleHalfHeight"), RowName, [&](float Val) { NewRow.CapsuleHalfHeight = Val; });
        TryApplyStringField(RowDataObject, TEXT("BodyMesh"), RowName, [&](const FString& Val) { NewRow.BodyMesh = Val; });
        TryApplyStringField(RowDataObject, TEXT("FaceMesh"), RowName, [&](const FString& Val) { NewRow.FaceMesh = Val; });
        TryApplyStringField(RowDataObject, TEXT("BodyAnimAssetPath"), RowName, [&](const FString& Val) { NewRow.BodyAnimAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FaceAnimAssetPath"), RowName, [&](const FString& Val) { NewRow.FaceAnimAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FaceAttachType"), RowName, [&](const FString& Val) { NewRow.FaceAttachType = Val; });
        TryApplyStringField(RowDataObject, TEXT("BattleToPeacefulShowPath"), RowName, [&](const FString& Val) { NewRow.BattleToPeacefulShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulToBattleShowPath"), RowName, [&](const FString& Val) { NewRow.PeacefulToBattleShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulToBattleShowPath_LockOn"), RowName, [&](const FString& Val) { NewRow.PeacefulToBattleShowPath_LockOn = Val; });
        TryApplyStringField(RowDataObject, TEXT("BattleToPeacefulShowPath_Move"), RowName, [&](const FString& Val) { NewRow.BattleToPeacefulShowPath_Move = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulToBattleShowPath_Move"), RowName, [&](const FString& Val) { NewRow.PeacefulToBattleShowPath_Move = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulToBattleShowPath_Move_LockOn"), RowName, [&](const FString& Val) { NewRow.PeacefulToBattleShowPath_Move_LockOn = Val; });
        TryApplyStringField(RowDataObject, TEXT("BattleToPeacefulShowPath_NoneAnim"), RowName, [&](const FString& Val) { NewRow.BattleToPeacefulShowPath_NoneAnim = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulToBattleShowPath_NoneAnim"), RowName, [&](const FString& Val) { NewRow.PeacefulToBattleShowPath_NoneAnim = Val; });
        TryApplyStringField(RowDataObject, TEXT("PeacefulToBattleShowPath_NoneAnim_LockOn"), RowName, [&](const FString& Val) { NewRow.PeacefulToBattleShowPath_NoneAnim_LockOn = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleToGroggyShowPath"), RowName, [&](const FString& Val) { NewRow.IdleToGroggyShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleToDownShowPath"), RowName, [&](const FString& Val) { NewRow.IdleToDownShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleToDeadShowPath"), RowName, [&](const FString& Val) { NewRow.IdleToDeadShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("IdleToAirborneShowPath"), RowName, [&](const FString& Val) { NewRow.IdleToAirborneShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("DownToIdleShowPath"), RowName, [&](const FString& Val) { NewRow.DownToIdleShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroggyToIdleShowPath"), RowName, [&](const FString& Val) { NewRow.GroggyToIdleShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("AirborneToIdleShowPath"), RowName, [&](const FString& Val) { NewRow.AirborneToIdleShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroggyToAirborneShowPath"), RowName, [&](const FString& Val) { NewRow.GroggyToAirborneShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("DownToAirborneShowPath"), RowName, [&](const FString& Val) { NewRow.DownToAirborneShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroggyToDownShowPath"), RowName, [&](const FString& Val) { NewRow.GroggyToDownShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("AirborneToDownShowPath"), RowName, [&](const FString& Val) { NewRow.AirborneToDownShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartSlopeShow"), RowName, [&](const FString& Val) { NewRow.StartSlopeShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("EndSlopeShow"), RowName, [&](const FString& Val) { NewRow.EndSlopeShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingAimToTakeBackShowPath"), RowName, [&](const FString& Val) { NewRow.FishingAimToTakeBackShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingTakeBackToAimShowPath"), RowName, [&](const FString& Val) { NewRow.FishingTakeBackToAimShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingTakeBackToCastingShowPath"), RowName, [&](const FString& Val) { NewRow.FishingTakeBackToCastingShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingCastingToWaitShowPath"), RowName, [&](const FString& Val) { NewRow.FishingCastingToWaitShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingWaitToFightShowPath"), RowName, [&](const FString& Val) { NewRow.FishingWaitToFightShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingWaitToIdleShowPath"), RowName, [&](const FString& Val) { NewRow.FishingWaitToIdleShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingFightToIdleShowPath"), RowName, [&](const FString& Val) { NewRow.FishingFightToIdleShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingCatchShowPath"), RowName, [&](const FString& Val) { NewRow.FishingCatchShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingLureChangeShowPath"), RowName, [&](const FString& Val) { NewRow.FishingLureChangeShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

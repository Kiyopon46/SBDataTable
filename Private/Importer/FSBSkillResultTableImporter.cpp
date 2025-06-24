#include "Importer/FSBSkillResultTableImporter.h"
#include "SBSkillResultTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBSkillResultTableImporter"

FString FSBSkillResultTableImporter::GetDataTableName() const
{
    return "SkillResultTable";
}

TFunction<void()> FSBSkillResultTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBSkillResultTableImporter::GetRowStruct() const
{
    return FSBSkillResultTableProperty::StaticStruct();
}

void FSBSkillResultTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBSkillResultTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfCommonEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfCommonEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetCommonEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetCommonEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetCommonEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetCommonEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfCommonShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfCommonShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetCommonShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetCommonShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetCommonMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetCommonMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetCommonMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetCommonMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfDownEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfDownEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetDownEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetDownEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetDownEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetDownEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfDownShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfDownShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetDownShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetDownShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetDownMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetDownMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetDownMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetDownMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfGroggyEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfGroggyEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetGroggyEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetGroggyEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetGroggyEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetGroggyEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfGroggyShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfGroggyShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetGroggyShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetGroggyShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetGroggyMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetGroggyMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetGroggyMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetGroggyMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfAirborneEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfAirborneEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetAirborneEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetAirborneEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetAirborneEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetAirborneEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfAirborneShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfAirborneShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetAirborneShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetAirborneShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetAirborneMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetAirborneMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetAirborneMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetAirborneMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfAirEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfAirEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetAirEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetAirEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetAirEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetAirEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfAirShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfAirShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetAirShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetAirShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetAirMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetAirMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetAirMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetAirMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfSwimmingEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfSwimmingEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetSwimmingEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetSwimmingEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetSwimmingEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetSwimmingEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfSwimmingShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfSwimmingShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetSwimmingShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetSwimmingShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetSwimmingMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetSwimmingMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetSwimmingMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetSwimmingMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfCriticalEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfCriticalEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetCriticalEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetCriticalEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfCriticalShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfCriticalShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetCriticalShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetCriticalShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfWeakpointHitEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfWeakpointHitEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetWeakpointHitEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetWeakpointHitEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfEventMovingEffect"), RowName, [&](const FString& Val) { NewRow.ResultSelfEventMovingEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetEventMovingEffect"), RowName, [&](const FString& Val) { NewRow.ResultTargetEventMovingEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetEventMovingEffect"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetEventMovingEffect = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultSelfEventMovingShowPath"), RowName, [&](const FString& Val) { NewRow.ResultSelfEventMovingShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetEventMovingShowPath"), RowName, [&](const FString& Val) { NewRow.ResultTargetEventMovingShowPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResultTargetEventMovingMoveAlias"), RowName, [&](const FString& Val) { NewRow.ResultTargetEventMovingMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("HitLevelResultTargetEventMovingMoveAlias"), RowName, [&](const FString& Val) { NewRow.HitLevelResultTargetEventMovingMoveAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBCharacterAnimMoveInfoTableImporter.h"
#include "SBCharacterAnimMoveInfoTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterAnimMoveInfoTableImporter"

FString FSBCharacterAnimMoveInfoTableImporter::GetDataTableName() const
{
    return "CharacterAnimMoveInfoTable";
}

TFunction<void()> FSBCharacterAnimMoveInfoTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterAnimMoveInfoTableImporter::GetRowStruct() const
{
    return FSBCharacterAnimMoveInfoTableProperty::StaticStruct();
}

void FSBCharacterAnimMoveInfoTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterAnimMoveInfoTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MovingDistance"), RowName, [&](float Val) { NewRow.MovingDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DelayDuration"), RowName, [&](float Val) { NewRow.DelayDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MovingDuration"), RowName, [&](float Val) { NewRow.MovingDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationDelayDuration"), RowName, [&](float Val) { NewRow.RotationDelayDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("RotationDuration"), RowName, [&](float Val) { NewRow.RotationDuration = Val; });
        TryApplyBoolField(RowDataObject, TEXT("LinearInterpRotation"), RowName, [&](bool Val) { NewRow.LinearInterpRotation = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AnimPlayDuration"), RowName, [&](float Val) { NewRow.AnimPlayDuration = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AnimBlendTime"), RowName, [&](float Val) { NewRow.AnimBlendTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InputBlockDuration"), RowName, [&](float Val) { NewRow.InputBlockDuration = Val; });
        TryApplyBoolField(RowDataObject, TEXT("LinearInterpLocation"), RowName, [&](bool Val) { NewRow.LinearInterpLocation = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bOverrideLinearInterpLocation"), RowName, [&](bool Val) { NewRow.bOverrideLinearInterpLocation = Val; });
        TryApplyIntField(RowDataObject, TEXT("RotationDirType"), RowName, [&](int32 Val) { NewRow.RotationDirType = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

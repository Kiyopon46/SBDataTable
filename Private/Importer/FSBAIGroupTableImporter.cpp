#include "Importer/FSBAIGroupTableImporter.h"
#include "SBAIGroupTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBAIGroupTableImporter"

FString FSBAIGroupTableImporter::GetDataTableName() const
{
    return "AIGroupTable";
}

TFunction<void()> FSBAIGroupTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBAIGroupTableImporter::GetRowStruct() const
{
    return FSBAIGroupTableProperty::StaticStruct();
}

void FSBAIGroupTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBAIGroupTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("MinGroupActorCount"), RowName, [&](int32 Val) { NewRow.MinGroupActorCount = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetShareCondition"), RowName, [&](const FString& Val) { NewRow.TargetShareCondition = Val; });
        TryApplyFloatField(RowDataObject, TEXT("TargetShareConditionValue"), RowName, [&](float Val) { NewRow.TargetShareConditionValue = Val; });
        TryApplyIntField(RowDataObject, TEXT("MaxAttackerCount"), RowName, [&](int32 Val) { NewRow.MaxAttackerCount = Val; });
        TryApplyFloatField(RowDataObject, TEXT("ReattackWaitingTime"), RowName, [&](float Val) { NewRow.ReattackWaitingTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("AttackerSelectMethod"), RowName, [&](const FString& Val) { NewRow.AttackerSelectMethod = Val; });
        TryApplyIntField(RowDataObject, TEXT("ValidProjectileCount"), RowName, [&](int32 Val) { NewRow.ValidProjectileCount = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InvalidProjectileOffsetMinDistance"), RowName, [&](float Val) { NewRow.InvalidProjectileOffsetMinDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InvalidProjectileOffsetMaxDistance"), RowName, [&](float Val) { NewRow.InvalidProjectileOffsetMaxDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CautionMinDistance"), RowName, [&](float Val) { NewRow.CautionMinDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CautionMaxDistance"), RowName, [&](float Val) { NewRow.CautionMaxDistance = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseMetaAIFormation"), RowName, [&](bool Val) { NewRow.bUseMetaAIFormation = Val; });
        TryApplyStringField(RowDataObject, TEXT("MetaAIFormationType"), RowName, [&](const FString& Val) { NewRow.MetaAIFormationType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bImmediatelyBattleAlarm"), RowName, [&](bool Val) { NewRow.bImmediatelyBattleAlarm = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

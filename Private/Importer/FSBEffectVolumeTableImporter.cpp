#include "Importer/FSBEffectVolumeTableImporter.h"
#include "SBEffectVolumeTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEffectVolumeTableImporter"

FString FSBEffectVolumeTableImporter::GetDataTableName() const
{
    return "EffectVolumeTable";
}

TFunction<void()> FSBEffectVolumeTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEffectVolumeTableImporter::GetRowStruct() const
{
    return FSBEffectVolumeTableProperty::StaticStruct();
}

void FSBEffectVolumeTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEffectVolumeTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitActivate"), RowName, [&](const FString& Val) { NewRow.InitActivate = Val; });
        TryApplyStringField(RowDataObject, TEXT("VolumeType"), RowName, [&](const FString& Val) { NewRow.VolumeType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActiveZoneAlias"), RowName, [&](const FString& Val) { NewRow.ActiveZoneAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnterEffectAlias"), RowName, [&](const FString& Val) { NewRow.EnterEffectAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AlwaysActiveEffectAlias"), RowName, [&](const FString& Val) { NewRow.AlwaysActiveEffectAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount01"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount01 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList01"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList01 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount02"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount02 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList02"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList02 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount03"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount03 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList03"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList03 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount04"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount04 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList04"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList04 = Val; });
        TryApplyStringField(RowDataObject, TEXT("PropertyData"), RowName, [&](const FString& Val) { NewRow.PropertyData = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResetType"), RowName, [&](const FString& Val) { NewRow.ResetType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResetTargetAlias"), RowName, [&](const FString& Val) { NewRow.ResetTargetAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ResetTargetState"), RowName, [&](const FString& Val) { NewRow.ResetTargetState = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseEveryZone"), RowName, [&](bool Val) { NewRow.bUseEveryZone = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

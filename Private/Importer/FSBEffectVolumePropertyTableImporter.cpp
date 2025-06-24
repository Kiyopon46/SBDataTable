#include "Importer/FSBEffectVolumePropertyTableImporter.h"
#include "SBEffectVolumePropTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEffectVolumePropertyTableImporter"

FString FSBEffectVolumePropertyTableImporter::GetDataTableName() const
{
    return "EffectVolumePropertyTable";
}

TFunction<void()> FSBEffectVolumePropertyTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEffectVolumePropertyTableImporter::GetRowStruct() const
{
    return FSBEffectVolumePropTableProperty::StaticStruct();
}

void FSBEffectVolumePropertyTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEffectVolumePropTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount01"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount01 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList01"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList01 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount02"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount02 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList02"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList02 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount03"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount03 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList03"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList03 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount04"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount04 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList04"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList04 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount05"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount05 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList05"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList05 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount06"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount06 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList06"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList06 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount07"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount07 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList07"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList07 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount08"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount08 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList08"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList08 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount09"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount09 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList09"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList09 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ExecuteDeadCount10"), RowName, [&](int32 Val) { NewRow.ExecuteDeadCount10 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DeadCountEffectAliasList10"), RowName, [&](const TArray<FString>& Val) { NewRow.DeadCountEffectAliasList10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

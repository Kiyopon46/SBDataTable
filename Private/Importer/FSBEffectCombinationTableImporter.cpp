#include "Importer/FSBEffectCombinationTableImporter.h"
#include "SBEffectCombinationTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEffectCombinationTableImporter"

FString FSBEffectCombinationTableImporter::GetDataTableName() const
{
    return "EffectCombinationTable";
}

TFunction<void()> FSBEffectCombinationTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEffectCombinationTableImporter::GetRowStruct() const
{
    return FSBEffectCombinationTableProperty::StaticStruct();
}

void FSBEffectCombinationTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEffectCombinationTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyStringField(RowDataObject, TEXT("Effect1"), RowName, [&](const FString& Val) { NewRow.Effect1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Effect1Count"), RowName, [&](int32 Val) { NewRow.Effect1Count = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepEffect1"), RowName, [&](bool Val) { NewRow.bKeepEffect1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Effect2"), RowName, [&](const FString& Val) { NewRow.Effect2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Effect2Count"), RowName, [&](int32 Val) { NewRow.Effect2Count = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepEffect2"), RowName, [&](bool Val) { NewRow.bKeepEffect2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Effect3"), RowName, [&](const FString& Val) { NewRow.Effect3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Effect3Count"), RowName, [&](int32 Val) { NewRow.Effect3Count = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepEffect3"), RowName, [&](bool Val) { NewRow.bKeepEffect3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Effect4"), RowName, [&](const FString& Val) { NewRow.Effect4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Effect4Count"), RowName, [&](int32 Val) { NewRow.Effect4Count = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepEffect4"), RowName, [&](bool Val) { NewRow.bKeepEffect4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Effect5"), RowName, [&](const FString& Val) { NewRow.Effect5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("Effect5Count"), RowName, [&](int32 Val) { NewRow.Effect5Count = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bKeepEffect5"), RowName, [&](bool Val) { NewRow.bKeepEffect5 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ResultEffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.ResultEffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBConditionTableImporter.h"
#include "SBConditionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBConditionTableImporter"

FString FSBConditionTableImporter::GetDataTableName() const
{
    return "ConditionTable";
}

TFunction<void()> FSBConditionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBConditionTableImporter::GetRowStruct() const
{
    return FSBConditionTableProperty::StaticStruct();
}

void FSBConditionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBConditionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionType"), RowName, [&](const FString& Val) { NewRow.ConditionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionEq"), RowName, [&](const FString& Val) { NewRow.ConditionEq = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStr01"), RowName, [&](const FString& Val) { NewRow.CustomStr01 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStr02"), RowName, [&](const FString& Val) { NewRow.CustomStr02 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStr03"), RowName, [&](const FString& Val) { NewRow.CustomStr03 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckStrValue"), RowName, [&](const FString& Val) { NewRow.CheckStrValue = Val; });
        TryApplyIntField(RowDataObject, TEXT("CheckValue"), RowName, [&](int32 Val) { NewRow.CheckValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("CheckStatCalcType"), RowName, [&](const FString& Val) { NewRow.CheckStatCalcType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorTargetType"), RowName, [&](const FString& Val) { NewRow.ActorTargetType = Val; });
        TryApplyStringField(RowDataObject, TEXT("GameOptionType"), RowName, [&](const FString& Val) { NewRow.GameOptionType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bUseActorTragetType"), RowName, [&](bool Val) { NewRow.bUseActorTragetType = Val; });
        TryApplyStringField(RowDataObject, TEXT("FailNotifyMsg"), RowName, [&](const FString& Val) { NewRow.FailNotifyMsg = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

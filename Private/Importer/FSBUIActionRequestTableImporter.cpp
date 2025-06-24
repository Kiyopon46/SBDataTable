#include "Importer/FSBUIActionRequestTableImporter.h"
#include "SBUIActionRequestTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBUIActionRequestTableImporter"

FString FSBUIActionRequestTableImporter::GetDataTableName() const
{
    return "UIActionRequestTable";
}

TFunction<void()> FSBUIActionRequestTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBUIActionRequestTableImporter::GetRowStruct() const
{
    return FSBUIActionRequestTableProperty::StaticStruct();
}

void FSBUIActionRequestTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBUIActionRequestTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Group"), RowName, [&](const FString& Val) { NewRow.Group = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyBoolField(RowDataObject, TEXT("BlockAction"), RowName, [&](bool Val) { NewRow.BlockAction = Val; });
        TryApplyBoolField(RowDataObject, TEXT("IgnoreLoadingScreen"), RowName, [&](bool Val) { NewRow.IgnoreLoadingScreen = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AffectedByVisibleOption"), RowName, [&](bool Val) { NewRow.AffectedByVisibleOption = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DebugClearAllow"), RowName, [&](bool Val) { NewRow.DebugClearAllow = Val; });
        TryApplyBoolField(RowDataObject, TEXT("SkipInNewGamePlus"), RowName, [&](bool Val) { NewRow.SkipInNewGamePlus = Val; });
        TryApplyBoolField(RowDataObject, TEXT("ConditionFailPass"), RowName, [&](bool Val) { NewRow.ConditionFailPass = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartConditionGroup"), RowName, [&](const FString& Val) { NewRow.StartConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("AchievementAction"), RowName, [&](const FString& Val) { NewRow.AchievementAction = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExecuteType"), RowName, [&](const FString& Val) { NewRow.ExecuteType = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Time"), RowName, [&](float Val) { NewRow.Time = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Delay"), RowName, [&](float Val) { NewRow.Delay = Val; });
        TryApplyStringField(RowDataObject, TEXT("FinishType"), RowName, [&](const FString& Val) { NewRow.FinishType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg1"), RowName, [&](const FString& Val) { NewRow.Arg1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg2"), RowName, [&](const FString& Val) { NewRow.Arg2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg3"), RowName, [&](const FString& Val) { NewRow.Arg3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AffectedByVisibleFailReplaceGroup"), RowName, [&](const FString& Val) { NewRow.AffectedByVisibleFailReplaceGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

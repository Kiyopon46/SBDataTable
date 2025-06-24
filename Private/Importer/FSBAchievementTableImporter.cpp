#include "Importer/FSBAchievementTableImporter.h"
#include "SBAchievementTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBAchievementTableImporter"

FString FSBAchievementTableImporter::GetDataTableName() const
{
    return "AchievementTable";
}

TFunction<void()> FSBAchievementTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBAchievementTableImporter::GetRowStruct() const
{
    return FSBAchievementTableProperty::StaticStruct();
}

void FSBAchievementTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBAchievementTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventType"), RowName, [&](const FString& Val) { NewRow.EventType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CategoryType"), RowName, [&](const FString& Val) { NewRow.CategoryType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("CheckParamOr"), RowName, [&](bool Val) { NewRow.CheckParamOr = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamType1"), RowName, [&](const FString& Val) { NewRow.ParamType1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamValue1"), RowName, [&](const FString& Val) { NewRow.ParamValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("OpType1"), RowName, [&](const FString& Val) { NewRow.OpType1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamType2"), RowName, [&](const FString& Val) { NewRow.ParamType2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamValue2"), RowName, [&](const FString& Val) { NewRow.ParamValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("OpType2"), RowName, [&](const FString& Val) { NewRow.OpType2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamType3"), RowName, [&](const FString& Val) { NewRow.ParamType3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamValue3"), RowName, [&](const FString& Val) { NewRow.ParamValue3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("OpType3"), RowName, [&](const FString& Val) { NewRow.OpType3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamType4"), RowName, [&](const FString& Val) { NewRow.ParamType4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("ParamValue4"), RowName, [&](const FString& Val) { NewRow.ParamValue4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("OpType4"), RowName, [&](const FString& Val) { NewRow.OpType4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("CompleteValue"), RowName, [&](int32 Val) { NewRow.CompleteValue = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CheckAchievementAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CheckAchievementAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("CompleteUIRequestGroup"), RowName, [&](const FString& Val) { NewRow.CompleteUIRequestGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CompleteAcquisitionSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.CompleteAcquisitionSkillArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RewardAcquisitionSkillArray"), RowName, [&](const TArray<FString>& Val) { NewRow.RewardAcquisitionSkillArray = Val; });
        TryApplyIntField(RowDataObject, TEXT("CompleteIncreaseMultiMapLevel"), RowName, [&](int32 Val) { NewRow.CompleteIncreaseMultiMapLevel = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProgressAchievementOnCompleted"), RowName, [&](const FString& Val) { NewRow.ProgressAchievementOnCompleted = Val; });
        TryApplyIntField(RowDataObject, TEXT("ProgressAchievementValueOnCompleted"), RowName, [&](int32 Val) { NewRow.ProgressAchievementValueOnCompleted = Val; });
        TryApplyStringField(RowDataObject, TEXT("ProgressAchievementOnCompleted2"), RowName, [&](const FString& Val) { NewRow.ProgressAchievementOnCompleted2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("ProgressAchievementValueOnCompleted2"), RowName, [&](int32 Val) { NewRow.ProgressAchievementValueOnCompleted2 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ProgressAchievementArrayOnCompleted"), RowName, [&](const TArray<FString>& Val) { NewRow.ProgressAchievementArrayOnCompleted = Val; });
        TryApplyIntField(RowDataObject, TEXT("ProgressAchievementArrayValueOnCompleted"), RowName, [&](int32 Val) { NewRow.ProgressAchievementArrayValueOnCompleted = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bMaintainNewGamePlus"), RowName, [&](bool Val) { NewRow.bMaintainNewGamePlus = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

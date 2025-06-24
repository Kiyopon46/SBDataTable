#include "Importer/FSBUITutorialTableImporter.h"
#include "SBUITutorialTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBUITutorialTableImporter"

FString FSBUITutorialTableImporter::GetDataTableName() const
{
    return "UITutorialTable";
}

TFunction<void()> FSBUITutorialTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBUITutorialTableImporter::GetRowStruct() const
{
    return FSBUITutorialTableProperty::StaticStruct();
}

void FSBUITutorialTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBUITutorialTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleStringKey"), RowName, [&](const FString& Val) { NewRow.TitleStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("DescStringKey"), RowName, [&](const FString& Val) { NewRow.DescStringKey = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bBlockNavigation"), RowName, [&](bool Val) { NewRow.bBlockNavigation = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnableInputAliases"), RowName, [&](const TArray<FString>& Val) { NewRow.EnableInputAliases = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("BlockingWidgetEventNameList"), RowName, [&](const TArray<FString>& Val) { NewRow.BlockingWidgetEventNameList = Val; });
        TryApplyStringField(RowDataObject, TEXT("NextTutorialAlias"), RowName, [&](const FString& Val) { NewRow.NextTutorialAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("OpenUILogicType"), RowName, [&](const FString& Val) { NewRow.OpenUILogicType = Val; });
        TryApplyStringField(RowDataObject, TEXT("OpenUIType"), RowName, [&](const FString& Val) { NewRow.OpenUIType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartConditionGroup"), RowName, [&](const FString& Val) { NewRow.StartConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("CompleteWidgetEventName"), RowName, [&](const FString& Val) { NewRow.CompleteWidgetEventName = Val; });
        TryApplyStringField(RowDataObject, TEXT("CompleteAchievementAlias"), RowName, [&](const FString& Val) { NewRow.CompleteAchievementAlias = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBEventGuideActionTableImporter.h"
#include "SBEventGuideActionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventGuideActionTableImporter"

FString FSBEventGuideActionTableImporter::GetDataTableName() const
{
    return "EventGuideActionTable";
}

TFunction<void()> FSBEventGuideActionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventGuideActionTableImporter::GetRowStruct() const
{
    return FSBEventGuideActionTableProperty::StaticStruct();
}

void FSBEventGuideActionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBEventGuideActionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ToTarget"), RowName, [&](const FString& Val) { NewRow.ToTarget = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetTagName"), RowName, [&](const FString& Val) { NewRow.TargetTagName = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FollowerTagNameArray"), RowName, [&](const TArray<FString>& Val) { NewRow.FollowerTagNameArray = Val; });
        TryApplyFloatField(RowDataObject, TEXT("FollowerStartDelayTime"), RowName, [&](float Val) { NewRow.FollowerStartDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("StopGuideAction"), RowName, [&](bool Val) { NewRow.StopGuideAction = Val; });
        TryApplyStringField(RowDataObject, TEXT("GuideActionAlias"), RowName, [&](const FString& Val) { NewRow.GuideActionAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

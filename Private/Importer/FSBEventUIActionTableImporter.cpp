#include "Importer/FSBEventUIActionTableImporter.h"
#include "SBZoneEventUIActionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBEventUIActionTableImporter"

FString FSBEventUIActionTableImporter::GetDataTableName() const
{
    return "EventUIActionTable";
}

TFunction<void()> FSBEventUIActionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBEventUIActionTableImporter::GetRowStruct() const
{
    return FSBZoneEventUIActionTableProperty::StaticStruct();
}

void FSBEventUIActionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBZoneEventUIActionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIActionType"), RowName, [&](const FString& Val) { NewRow.UIActionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("UILogicType"), RowName, [&](const FString& Val) { NewRow.UILogicType = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIActionRequestIndex"), RowName, [&](const FString& Val) { NewRow.UIActionRequestIndex = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DrawDuration"), RowName, [&](float Val) { NewRow.DrawDuration = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStrValue1"), RowName, [&](const FString& Val) { NewRow.CustomStrValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("CustomStrValue2"), RowName, [&](const FString& Val) { NewRow.CustomStrValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventCondition"), RowName, [&](const FString& Val) { NewRow.EventCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventConditionGroup"), RowName, [&](const FString& Val) { NewRow.EventConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventorType"), RowName, [&](const FString& Val) { NewRow.EventorType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bHUDInputLock"), RowName, [&](bool Val) { NewRow.bHUDInputLock = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bGameMenuInputLock"), RowName, [&](bool Val) { NewRow.bGameMenuInputLock = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

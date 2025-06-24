#include "Importer/FSBUITextActionFormatTableImporter.h"
#include "SBUITextActionFormatTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBUITextActionFormatTableImporter"

FString FSBUITextActionFormatTableImporter::GetDataTableName() const
{
    return "UITextActionFormatTable";
}

TFunction<void()> FSBUITextActionFormatTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBUITextActionFormatTableImporter::GetRowStruct() const
{
    return FSBUITextActionFormatTableProperty::StaticStruct();
}

void FSBUITextActionFormatTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBUITextActionFormatTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Group"), RowName, [&](const FString& Val) { NewRow.Group = Val; });
        TryApplyStringField(RowDataObject, TEXT("GameOptionType"), RowName, [&](const FString& Val) { NewRow.GameOptionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("GameOptionRedirectValue1"), RowName, [&](const FString& Val) { NewRow.GameOptionRedirectValue1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("GameOptionRedirectValue2"), RowName, [&](const FString& Val) { NewRow.GameOptionRedirectValue2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("StreamInputRedirectValue"), RowName, [&](const FString& Val) { NewRow.StreamInputRedirectValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("Platform"), RowName, [&](const FString& Val) { NewRow.Platform = Val; });
        TryApplyStringField(RowDataObject, TEXT("FallBackGroupAlias"), RowName, [&](const FString& Val) { NewRow.FallBackGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringTableNamespace"), RowName, [&](const FString& Val) { NewRow.StringTableNamespace = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringTableKey"), RowName, [&](const FString& Val) { NewRow.StringTableKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringFormat"), RowName, [&](const FString& Val) { NewRow.StringFormat = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action1"), RowName, [&](const FString& Val) { NewRow.Action1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAction1"), RowName, [&](int32 Val) { NewRow.SortAction1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action2"), RowName, [&](const FString& Val) { NewRow.Action2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAction2"), RowName, [&](int32 Val) { NewRow.SortAction2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action3"), RowName, [&](const FString& Val) { NewRow.Action3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAction3"), RowName, [&](int32 Val) { NewRow.SortAction3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action4"), RowName, [&](const FString& Val) { NewRow.Action4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAction4"), RowName, [&](int32 Val) { NewRow.SortAction4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Action5"), RowName, [&](const FString& Val) { NewRow.Action5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAction5"), RowName, [&](int32 Val) { NewRow.SortAction5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputDefine1"), RowName, [&](const FString& Val) { NewRow.InputDefine1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortInputDefine1"), RowName, [&](int32 Val) { NewRow.SortInputDefine1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputDefine2"), RowName, [&](const FString& Val) { NewRow.InputDefine2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortInputDefine2"), RowName, [&](int32 Val) { NewRow.SortInputDefine2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputDefine3"), RowName, [&](const FString& Val) { NewRow.InputDefine3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortInputDefine3"), RowName, [&](int32 Val) { NewRow.SortInputDefine3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputDefine4"), RowName, [&](const FString& Val) { NewRow.InputDefine4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortInputDefine4"), RowName, [&](int32 Val) { NewRow.SortInputDefine4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("InputDefine5"), RowName, [&](const FString& Val) { NewRow.InputDefine5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortInputDefine5"), RowName, [&](int32 Val) { NewRow.SortInputDefine5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Axis1"), RowName, [&](const FString& Val) { NewRow.Axis1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AxisScale1"), RowName, [&](const FString& Val) { NewRow.AxisScale1 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAxis1"), RowName, [&](int32 Val) { NewRow.SortAxis1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Axis2"), RowName, [&](const FString& Val) { NewRow.Axis2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AxisScale2"), RowName, [&](const FString& Val) { NewRow.AxisScale2 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAxis2"), RowName, [&](int32 Val) { NewRow.SortAxis2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Axis3"), RowName, [&](const FString& Val) { NewRow.Axis3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AxisScale3"), RowName, [&](const FString& Val) { NewRow.AxisScale3 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAxis3"), RowName, [&](int32 Val) { NewRow.SortAxis3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Axis4"), RowName, [&](const FString& Val) { NewRow.Axis4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AxisScale4"), RowName, [&](const FString& Val) { NewRow.AxisScale4 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAxis4"), RowName, [&](int32 Val) { NewRow.SortAxis4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Axis5"), RowName, [&](const FString& Val) { NewRow.Axis5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("AxisScale5"), RowName, [&](const FString& Val) { NewRow.AxisScale5 = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortAxis5"), RowName, [&](int32 Val) { NewRow.SortAxis5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("SwipeOption"), RowName, [&](const FString& Val) { NewRow.SwipeOption = Val; });
        TryApplyIntField(RowDataObject, TEXT("SortSwipeOption"), RowName, [&](int32 Val) { NewRow.SortSwipeOption = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

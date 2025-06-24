#include "Importer/FSBGuideMessageTableImporter.h"
#include "SBGuideMessageTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBGuideMessageTableImporter"

FString FSBGuideMessageTableImporter::GetDataTableName() const
{
    return "GuideMessageTable";
}

TFunction<void()> FSBGuideMessageTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBGuideMessageTableImporter::GetRowStruct() const
{
    return FSBGuideMessageTableProperty::StaticStruct();
}

void FSBGuideMessageTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBGuideMessageTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyIntField(RowDataObject, TEXT("Priority"), RowName, [&](int32 Val) { NewRow.Priority = Val; });
        TryApplyStringField(RowDataObject, TEXT("MessageType"), RowName, [&](const FString& Val) { NewRow.MessageType = Val; });
        TryApplyStringField(RowDataObject, TEXT("StringKey"), RowName, [&](const FString& Val) { NewRow.StringKey = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DisplayTime"), RowName, [&](float Val) { NewRow.DisplayTime = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DisplayPositionX"), RowName, [&](float Val) { NewRow.DisplayPositionX = Val; });
        TryApplyStringField(RowDataObject, TEXT("DisplayType"), RowName, [&](const FString& Val) { NewRow.DisplayType = Val; });
        TryApplyStringField(RowDataObject, TEXT("GuideStartType"), RowName, [&](const FString& Val) { NewRow.GuideStartType = Val; });
        TryApplyIntField(RowDataObject, TEXT("StartValue"), RowName, [&](int32 Val) { NewRow.StartValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("GuideCompleteType"), RowName, [&](const FString& Val) { NewRow.GuideCompleteType = Val; });
        TryApplyIntField(RowDataObject, TEXT("CompleteValue"), RowName, [&](int32 Val) { NewRow.CompleteValue = Val; });
        TryApplyBoolField(RowDataObject, TEXT("CustomBool"), RowName, [&](bool Val) { NewRow.CustomBool = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("CustomAliases"), RowName, [&](const TArray<FString>& Val) { NewRow.CustomAliases = Val; });
        TryApplyStringField(RowDataObject, TEXT("Command"), RowName, [&](const FString& Val) { NewRow.Command = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorCondition"), RowName, [&](const FString& Val) { NewRow.ActorCondition = Val; });
        TryApplyStringField(RowDataObject, TEXT("FishingMode"), RowName, [&](const FString& Val) { NewRow.FishingMode = Val; });
        TryApplyStringField(RowDataObject, TEXT("GuideCompleteAchievementAlias"), RowName, [&](const FString& Val) { NewRow.GuideCompleteAchievementAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("GuideTimeOutAchievementAlias"), RowName, [&](const FString& Val) { NewRow.GuideTimeOutAchievementAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("GuideSkipAchievementAlias"), RowName, [&](const FString& Val) { NewRow.GuideSkipAchievementAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartConditionGroup"), RowName, [&](const FString& Val) { NewRow.StartConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("CancelConditionGroup"), RowName, [&](const FString& Val) { NewRow.CancelConditionGroup = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIActionRequestGroup"), RowName, [&](const FString& Val) { NewRow.UIActionRequestGroup = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bAffectedByVisibleOption"), RowName, [&](bool Val) { NewRow.bAffectedByVisibleOption = Val; });
        TryApplyIntField(RowDataObject, TEXT("ForceSlotIndex"), RowName, [&](int32 Val) { NewRow.ForceSlotIndex = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DontShowInNewGamePlus"), RowName, [&](bool Val) { NewRow.DontShowInNewGamePlus = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

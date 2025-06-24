#include "Importer/FSBAcquisitionSkillTableImporter.h"
#include "SBAcquisitionSkillTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBAcquisitionSkillTableImporter"

FString FSBAcquisitionSkillTableImporter::GetDataTableName() const
{
    return "AcquisitionSkillTable";
}

TFunction<void()> FSBAcquisitionSkillTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBAcquisitionSkillTableImporter::GetRowStruct() const
{
    return FSBAcquisitionSkillTableProperty::StaticStruct();
}

void FSBAcquisitionSkillTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBAcquisitionSkillTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Type"), RowName, [&](const FString& Val) { NewRow.Type = Val; });
        TryApplyStringField(RowDataObject, TEXT("UsableSlot"), RowName, [&](const FString& Val) { NewRow.UsableSlot = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConsumeItemAlias"), RowName, [&](const FString& Val) { NewRow.ConsumeItemAlias = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConsumeItemAmount"), RowName, [&](int32 Val) { NewRow.ConsumeItemAmount = Val; });
        TryApplyIntField(RowDataObject, TEXT("ConsumeSP"), RowName, [&](int32 Val) { NewRow.ConsumeSP = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bExceptReset"), RowName, [&](bool Val) { NewRow.bExceptReset = Val; });
        TryApplyStringField(RowDataObject, TEXT("RequiredCompleteAchievement"), RowName, [&](const FString& Val) { NewRow.RequiredCompleteAchievement = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("RequiredAcquisitionSkillAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.RequiredAcquisitionSkillAliasArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("OrCheckRequiredAcquisition"), RowName, [&](bool Val) { NewRow.OrCheckRequiredAcquisition = Val; });
        TryApplyStringField(RowDataObject, TEXT("VisibleCondition"), RowName, [&](const FString& Val) { NewRow.VisibleCondition = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AcquisitionOnCreated"), RowName, [&](bool Val) { NewRow.AcquisitionOnCreated = Val; });
        TryApplyStringField(RowDataObject, TEXT("PassiveSkillFunctionAlias"), RowName, [&](const FString& Val) { NewRow.PassiveSkillFunctionAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillIconName"), RowName, [&](const FString& Val) { NewRow.SkillIconName = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillPreviewPath"), RowName, [&](const FString& Val) { NewRow.SkillPreviewPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillEnergyVisibleType"), RowName, [&](const FString& Val) { NewRow.SkillEnergyVisibleType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillImportanceType"), RowName, [&](const FString& Val) { NewRow.SkillImportanceType = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillTreeAlias"), RowName, [&](const FString& Val) { NewRow.SkillTreeAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillSlotAlias"), RowName, [&](const FString& Val) { NewRow.SkillSlotAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AchievementTag"), RowName, [&](const FString& Val) { NewRow.AchievementTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleName"), RowName, [&](const FString& Val) { NewRow.TitleName = Val; });
        TryApplyStringField(RowDataObject, TEXT("Description"), RowName, [&](const FString& Val) { NewRow.Description = Val; });
        TryApplyStringField(RowDataObject, TEXT("Command"), RowName, [&](const FString& Val) { NewRow.Command = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillPriorityAlias"), RowName, [&](const FString& Val) { NewRow.SkillPriorityAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("SkillCommandAlias"), RowName, [&](const FString& Val) { NewRow.SkillCommandAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("TrainingRoom"), RowName, [&](const FString& Val) { NewRow.TrainingRoom = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

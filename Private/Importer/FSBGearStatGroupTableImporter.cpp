#include "Importer/FSBGearStatGroupTableImporter.h"
#include "SBGearStatGroupTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBGearStatGroupTableImporter"

FString FSBGearStatGroupTableImporter::GetDataTableName() const
{
    return "GearStatGroupTable";
}

TFunction<void()> FSBGearStatGroupTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBGearStatGroupTableImporter::GetRowStruct() const
{
    return FSBGearStatGroupTableProperty::StaticStruct();
}

void FSBGearStatGroupTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBGearStatGroupTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("Group"), RowName, [&](const FString& Val) { NewRow.Group = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCategoryTag"), RowName, [&](const FString& Val) { NewRow.StatCategoryTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("GearStatType"), RowName, [&](const FString& Val) { NewRow.GearStatType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorStatType"), RowName, [&](const FString& Val) { NewRow.ActorStatType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectStatTag"), RowName, [&](const FString& Val) { NewRow.EffectStatTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

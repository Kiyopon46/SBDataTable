#include "Importer/FSBGearStatTableImporter.h"
#include "SBGearStatTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBGearStatTableImporter"

FString FSBGearStatTableImporter::GetDataTableName() const
{
    return "GearStatTable";
}

TFunction<void()> FSBGearStatTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBGearStatTableImporter::GetRowStruct() const
{
    return FSBGearStatTableProperty::StaticStruct();
}

void FSBGearStatTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBGearStatTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("StatCategoryTag"), RowName, [&](const FString& Val) { NewRow.StatCategoryTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("GearStatType"), RowName, [&](const FString& Val) { NewRow.GearStatType = Val; });
        TryApplyStringField(RowDataObject, TEXT("ActorStatType"), RowName, [&](const FString& Val) { NewRow.ActorStatType = Val; });
        TryApplyStringField(RowDataObject, TEXT("EffectStatTag"), RowName, [&](const FString& Val) { NewRow.EffectStatTag = Val; });
        TryApplyIntField(RowDataObject, TEXT("StatLevel"), RowName, [&](int32 Val) { NewRow.StatLevel = Val; });
        TryApplyStringField(RowDataObject, TEXT("Rarity"), RowName, [&](const FString& Val) { NewRow.Rarity = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValueMin"), RowName, [&](float Val) { NewRow.StatValueMin = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StatValueMax"), RowName, [&](float Val) { NewRow.StatValueMax = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EffectAliasArray"), RowName, [&](const TArray<FString>& Val) { NewRow.EffectAliasArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("TextEffectName"), RowName, [&](const FString& Val) { NewRow.TextEffectName = Val; });
        TryApplyStringField(RowDataObject, TEXT("TextEffectDesc"), RowName, [&](const FString& Val) { NewRow.TextEffectDesc = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

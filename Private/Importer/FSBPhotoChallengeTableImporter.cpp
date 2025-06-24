#include "Importer/FSBPhotoChallengeTableImporter.h"
#include "SBPhotoChallengeTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoChallengeTableImporter"

FString FSBPhotoChallengeTableImporter::GetDataTableName() const
{
    return "PhotoChallengeTable";
}

TFunction<void()> FSBPhotoChallengeTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBPhotoChallengeTableImporter::GetRowStruct() const
{
    return FSBPhotoChallengeTableProperty::StaticStruct();
}

void FSBPhotoChallengeTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBPhotoChallengeTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetZoneEnvActorAlias"), RowName, [&](const FString& Val) { NewRow.TargetZoneEnvActorAlias = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckDistance"), RowName, [&](float Val) { NewRow.CheckDistance = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckAngle"), RowName, [&](float Val) { NewRow.CheckAngle = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckBoxRatioX"), RowName, [&](float Val) { NewRow.CheckBoxRatioX = Val; });
        TryApplyFloatField(RowDataObject, TEXT("CheckBoxRatioY"), RowName, [&](float Val) { NewRow.CheckBoxRatioY = Val; });
        TryApplyStringField(RowDataObject, TEXT("LinkedQuestTaskAlias"), RowName, [&](const FString& Val) { NewRow.LinkedQuestTaskAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("ExceptActorAlias"), RowName, [&](const FString& Val) { NewRow.ExceptActorAlias = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBStudioTransitionTableImporter.h"
#include "SBStudioTransitionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBStudioTransitionTableImporter"

FString FSBStudioTransitionTableImporter::GetDataTableName() const
{
    return "StudioTransitionTable";
}

TFunction<void()> FSBStudioTransitionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBStudioTransitionTableImporter::GetRowStruct() const
{
    return FSBStudioTransitionTableProperty::StaticStruct();
}

void FSBStudioTransitionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBStudioTransitionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("StartState"), RowName, [&](const FString& Val) { NewRow.StartState = Val; });
        TryApplyStringField(RowDataObject, TEXT("TargetState"), RowName, [&](const FString& Val) { NewRow.TargetState = Val; });
        TryApplyStringField(RowDataObject, TEXT("TransitionShowTag"), RowName, [&](const FString& Val) { NewRow.TransitionShowTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("TransitionSequenceTag"), RowName, [&](const FString& Val) { NewRow.TransitionSequenceTag = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bFade"), RowName, [&](bool Val) { NewRow.bFade = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

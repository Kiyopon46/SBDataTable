#include "Importer/FSBAreaControlVolumeTableImporter.h"
#include "SBAreaControlVolumeTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBAreaControlVolumeTableImporter"

FString FSBAreaControlVolumeTableImporter::GetDataTableName() const
{
    return "AreaControlVolumeTable";
}

TFunction<void()> FSBAreaControlVolumeTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBAreaControlVolumeTableImporter::GetRowStruct() const
{
    return FSBAreaControlVolumeTableProperty::StaticStruct();
}

void FSBAreaControlVolumeTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBAreaControlVolumeTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("InitActivate"), RowName, [&](const FString& Val) { NewRow.InitActivate = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AdmissionPossibleTribeArray"), RowName, [&](const TArray<FString>& Val) { NewRow.AdmissionPossibleTribeArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AdmissionPossibleCharacterTagArray"), RowName, [&](const TArray<FString>& Val) { NewRow.AdmissionPossibleCharacterTagArray = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bRemoveNotKeepSBCharacter"), RowName, [&](bool Val) { NewRow.bRemoveNotKeepSBCharacter = Val; });
        TryApplyStringField(RowDataObject, TEXT("SaveType"), RowName, [&](const FString& Val) { NewRow.SaveType = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

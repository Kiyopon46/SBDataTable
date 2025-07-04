#include "Importer/FSBPhotoModeImageTableImporter.h"
#include "SBPhotoModeImageTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoModeImageTableImporter"

FString FSBPhotoModeImageTableImporter::GetDataTableName() const
{
    return "PhotoModeImageTable";
}

TFunction<void()> FSBPhotoModeImageTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBPhotoModeImageTableImporter::GetRowStruct() const
{
    return FSBPhotoModeImageTableProperty::StaticStruct();
}

void FSBPhotoModeImageTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBPhotoModeImageTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("UIOperateArray"), RowName, [&](const TArray<FString>& Val) { NewRow.UIOperateArray = Val; });
        TryApplyStringField(RowDataObject, TEXT("OptionStringKey"), RowName, [&](const FString& Val) { NewRow.OptionStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ImagePath"), RowName, [&](const FString& Val) { NewRow.ImagePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("EnableConditionGroup"), RowName, [&](const FString& Val) { NewRow.EnableConditionGroup = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBMailBoxGiftTableImporter.h"
#include "SBMailBoxGiftTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBMailBoxGiftTableImporter"

FString FSBMailBoxGiftTableImporter::GetDataTableName() const
{
    return "MailBoxGiftTable";
}

TFunction<void()> FSBMailBoxGiftTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBMailBoxGiftTableImporter::GetRowStruct() const
{
    return FSBMailBoxGiftTableProperty::StaticStruct();
}

void FSBMailBoxGiftTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBMailBoxGiftTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleStringKey"), RowName, [&](const FString& Val) { NewRow.TitleStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("DescStringKey"), RowName, [&](const FString& Val) { NewRow.DescStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ReceivableConditionGroup"), RowName, [&](const FString& Val) { NewRow.ReceivableConditionGroup = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("EnableMailBoxEnvSpawnList"), RowName, [&](const TArray<FString>& Val) { NewRow.EnableMailBoxEnvSpawnList = Val; });
        TryApplyStringField(RowDataObject, TEXT("EventGiftAlias"), RowName, [&](const FString& Val) { NewRow.EventGiftAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("MailImagePath"), RowName, [&](const FString& Val) { NewRow.MailImagePath = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

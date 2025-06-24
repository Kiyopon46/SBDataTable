#include "Importer/FSBCreditTableImporter.h"
#include "SBCreditTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCreditTableImporter"

FString FSBCreditTableImporter::GetDataTableName() const
{
    return "CreditTable";
}

TFunction<void()> FSBCreditTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCreditTableImporter::GetRowStruct() const
{
    return FSBCreditTableProperty::StaticStruct();
}

void FSBCreditTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCreditTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("VoiceLanguage"), RowName, [&](const FString& Val) { NewRow.VoiceLanguage = Val; });
        TryApplyStringField(RowDataObject, TEXT("CreditType"), RowName, [&](const FString& Val) { NewRow.CreditType = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg1"), RowName, [&](const FString& Val) { NewRow.Arg1 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg2"), RowName, [&](const FString& Val) { NewRow.Arg2 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg3"), RowName, [&](const FString& Val) { NewRow.Arg3 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg4"), RowName, [&](const FString& Val) { NewRow.Arg4 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg5"), RowName, [&](const FString& Val) { NewRow.Arg5 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg6"), RowName, [&](const FString& Val) { NewRow.Arg6 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg7"), RowName, [&](const FString& Val) { NewRow.Arg7 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg8"), RowName, [&](const FString& Val) { NewRow.Arg8 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg9"), RowName, [&](const FString& Val) { NewRow.Arg9 = Val; });
        TryApplyStringField(RowDataObject, TEXT("Arg10"), RowName, [&](const FString& Val) { NewRow.Arg10 = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

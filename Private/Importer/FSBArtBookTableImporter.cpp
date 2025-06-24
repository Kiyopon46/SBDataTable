#include "Importer/FSBArtBookTableImporter.h"
#include "SBArtBookTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBArtBookTableImporter"

FString FSBArtBookTableImporter::GetDataTableName() const
{
    return "ArtBookTable";
}

TFunction<void()> FSBArtBookTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBArtBookTableImporter::GetRowStruct() const
{
    return FSBArtBookTableProperty::StaticStruct();
}

void FSBArtBookTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBArtBookTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupAlias"), RowName, [&](const FString& Val) { NewRow.GroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("TitleStringKey"), RowName, [&](const FString& Val) { NewRow.TitleStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ArtistStringKey"), RowName, [&](const FString& Val) { NewRow.ArtistStringKey = Val; });
        TryApplyStringField(RowDataObject, TEXT("ImagePath"), RowName, [&](const FString& Val) { NewRow.ImagePath = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

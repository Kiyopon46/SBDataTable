#include "Importer/FSBNikkeLostArticleTableImporter.h"
#include "SBNikkeLostArticleTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBNikkeLostArticleTableImporter"

FString FSBNikkeLostArticleTableImporter::GetDataTableName() const
{
    return "NikkeLostArticleTable";
}

TFunction<void()> FSBNikkeLostArticleTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBNikkeLostArticleTableImporter::GetRowStruct() const
{
    return FSBNikkeLostArticleTableProperty::StaticStruct();
}

void FSBNikkeLostArticleTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBNikkeLostArticleTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("ClearShowTag"), RowName, [&](const FString& Val) { NewRow.ClearShowTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("ClearSequenceTag"), RowName, [&](const FString& Val) { NewRow.ClearSequenceTag = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemSkeletalMeshPath"), RowName, [&](const FString& Val) { NewRow.ItemSkeletalMeshPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemAnimAssetPath"), RowName, [&](const FString& Val) { NewRow.ItemAnimAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("ItemMeshTag"), RowName, [&](const FString& Val) { NewRow.ItemMeshTag = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ClearNikkeStageAlias"), RowName, [&](const TArray<FString>& Val) { NewRow.ClearNikkeStageAlias = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ClearSequencePath"), RowName, [&](const TArray<FString>& Val) { NewRow.ClearSequencePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("ClearSequenceUITime"), RowName, [&](const TArray<FString>& Val) { NewRow.ClearSequenceUITime = Val; });
        TryApplyStringField(RowDataObject, TEXT("ClearRewardGroupAlias"), RowName, [&](const FString& Val) { NewRow.ClearRewardGroupAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("Category"), RowName, [&](const FString& Val) { NewRow.Category = Val; });
        TryApplyStringField(RowDataObject, TEXT("ImageAssetPath"), RowName, [&](const FString& Val) { NewRow.ImageAssetPath = Val; });
        TryApplyStringField(RowDataObject, TEXT("MusicQNRTAssetPath"), RowName, [&](const FString& Val) { NewRow.MusicQNRTAssetPath = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBAlbumTableImporter.h"
#include "SBAlbumTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBAlbumTableImporter"

FString FSBAlbumTableImporter::GetDataTableName() const
{
    return "AlbumTable";
}

TFunction<void()> FSBAlbumTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBAlbumTableImporter::GetRowStruct() const
{
    return FSBAlbumTableProperty::StaticStruct();
}

void FSBAlbumTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBAlbumTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("EntityAlias"), RowName, [&](const FString& Val) { NewRow.EntityAlias = Val; });
        TryApplyStringField(RowDataObject, TEXT("AlbumType"), RowName, [&](const FString& Val) { NewRow.AlbumType = Val; });
        TryApplyBoolField(RowDataObject, TEXT("PopupWhenUnlock"), RowName, [&](bool Val) { NewRow.PopupWhenUnlock = Val; });
        TryApplyBoolField(RowDataObject, TEXT("PauseWhenPopup"), RowName, [&](bool Val) { NewRow.PauseWhenPopup = Val; });
        TryApplyStringField(RowDataObject, TEXT("GroupName"), RowName, [&](const FString& Val) { NewRow.GroupName = Val; });
        TryApplyStringField(RowDataObject, TEXT("Name"), RowName, [&](const FString& Val) { NewRow.Name = Val; });
        TryApplyStringField(RowDataObject, TEXT("Desc"), RowName, [&](const FString& Val) { NewRow.Desc = Val; });
        TryApplyStringField(RowDataObject, TEXT("Asset2DIcon"), RowName, [&](const FString& Val) { NewRow.Asset2DIcon = Val; });
        TryApplyStringField(RowDataObject, TEXT("Asset2DImage"), RowName, [&](const FString& Val) { NewRow.Asset2DImage = Val; });
        TryApplyStringField(RowDataObject, TEXT("AchievementUnlocked"), RowName, [&](const FString& Val) { NewRow.AchievementUnlocked = Val; });
        TryApplyStringField(RowDataObject, TEXT("AchievementUsed"), RowName, [&](const FString& Val) { NewRow.AchievementUsed = Val; });
        TryApplyStringField(RowDataObject, TEXT("AchievementPopup"), RowName, [&](const FString& Val) { NewRow.AchievementPopup = Val; });
        TryApplyStringField(RowDataObject, TEXT("ConditionGroupDisplay"), RowName, [&](const FString& Val) { NewRow.ConditionGroupDisplay = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

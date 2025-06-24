#pragma once

#include "FSBDataTableImporter.h"
#include "SBAlbumTableProperty.h"

/**
 * Importer for AlbumTable.
 */
class SB_API FSBAlbumTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
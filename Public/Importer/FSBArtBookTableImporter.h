#pragma once

#include "FSBDataTableImporter.h"
#include "SBArtBookTableProperty.h"

/**
 * Importer for ArtBookTable.
 */
class SB_API FSBArtBookTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
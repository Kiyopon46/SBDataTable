#pragma once

#include "FSBDataTableImporter.h"
#include "SBIsolatedAreaTableProperty.h"

/**
 * Importer for IsolatedAreaTable.
 */
class SB_API FSBIsolatedAreaTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBKeyMappingTableProperty.h"

/**
 * Importer for KeyMappingTable.
 */
class SB_API FSBKeyMappingTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
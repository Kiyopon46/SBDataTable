#pragma once

#include "FSBDataTableImporter.h"
#include "SBKeyMappingRolloverTableProperty.h"

/**
 * Importer for KeyMappingRolloverTable.
 */
class SB_API FSBKeyMappingRolloverTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
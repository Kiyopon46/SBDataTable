#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemConsumableTableProperty.h"

/**
 * Importer for ItemConsumableTable.
 */
class SB_API FSBItemConsumableTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
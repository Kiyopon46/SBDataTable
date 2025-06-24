#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemLureTableProperty.h"

/**
 * Importer for ItemLureTable.
 */
class SB_API FSBItemLureTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
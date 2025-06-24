#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemTableProperty.h"

/**
 * Importer for ItemTable.
 */
class SB_API FSBItemTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
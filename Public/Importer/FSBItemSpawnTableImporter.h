#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemSpawnTableProperty.h"

/**
 * Importer for ItemSpawnTable.
 */
class SB_API FSBItemSpawnTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
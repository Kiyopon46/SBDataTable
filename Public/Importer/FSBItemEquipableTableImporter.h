#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemEquipableTableProperty.h"

/**
 * Importer for ItemEquipableTable.
 */
class SB_API FSBItemEquipableTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
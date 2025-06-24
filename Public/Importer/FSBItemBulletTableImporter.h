#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemBulletTableProperty.h"

/**
 * Importer for ItemBulletTable.
 */
class SB_API FSBItemBulletTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
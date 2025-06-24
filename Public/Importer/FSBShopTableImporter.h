#pragma once

#include "FSBDataTableImporter.h"
#include "SBShopTableProperty.h"

/**
 * Importer for ShopTable.
 */
class SB_API FSBShopTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemFishTableProperty.h"

/**
 * Importer for ItemFishTable.
 */
class SB_API FSBItemFishTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
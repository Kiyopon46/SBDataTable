#pragma once

#include "FSBDataTableImporter.h"
#include "SBDropRateAdjustTableTableProperty.h"

/**
 * Importer for DropRateAdjustTable.
 */
class SB_API FSBDropRateAdjustTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
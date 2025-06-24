#pragma once

#include "FSBDataTableImporter.h"
#include "SBUIKeyImageAssetProperty.h"

/**
 * Importer for UIKeyImageAssetTable.
 */
class SB_API FSBUIKeyImageAssetTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
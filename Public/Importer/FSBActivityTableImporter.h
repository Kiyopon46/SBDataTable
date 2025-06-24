#pragma once

#include "FSBDataTableImporter.h"
#include "SBActivityTableProperty.h"

/**
 * Importer for ActivityTable.
 */
class SB_API FSBActivityTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
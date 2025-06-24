#pragma once

#include "FSBDataTableImporter.h"
#include "SBAIGroupTableProperty.h"

/**
 * Importer for AIGroupTable.
 */
class SB_API FSBAIGroupTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
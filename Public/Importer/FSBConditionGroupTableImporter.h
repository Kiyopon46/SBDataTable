#pragma once

#include "FSBDataTableImporter.h"
#include "SBConditionGroupTableProperty.h"

/**
 * Importer for ConditionGroupTable.
 */
class SB_API FSBConditionGroupTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBConditionTableProperty.h"

/**
 * Importer for ConditionTable.
 */
class SB_API FSBConditionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
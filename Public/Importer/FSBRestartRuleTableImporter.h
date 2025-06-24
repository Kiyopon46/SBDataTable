#pragma once

#include "FSBDataTableImporter.h"
#include "SBRestartRuleTableProperty.h"

/**
 * Importer for RestartRuleTable.
 */
class SB_API FSBRestartRuleTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
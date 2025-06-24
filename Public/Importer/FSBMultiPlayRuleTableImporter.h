#pragma once

#include "FSBDataTableImporter.h"
#include "SBMultiPlayRuleTableProperty.h"

/**
 * Importer for MultiPlayRuleTable.
 */
class SB_API FSBMultiPlayRuleTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
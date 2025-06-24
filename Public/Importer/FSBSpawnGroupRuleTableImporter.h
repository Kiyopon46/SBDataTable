#pragma once

#include "FSBDataTableImporter.h"
#include "SBSpawnGroupRuleTableProperty.h"

/**
 * Importer for SpawnGroupRuleTable.
 */
class SB_API FSBSpawnGroupRuleTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
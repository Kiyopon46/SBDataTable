#pragma once

#include "FSBDataTableImporter.h"
#include "SBSkillPriorityTableProperty.h"

/**
 * Importer for SkillPriorityTable.
 */
class SB_API FSBSkillPriorityTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
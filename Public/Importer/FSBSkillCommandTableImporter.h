#pragma once

#include "FSBDataTableImporter.h"
#include "SBSkillCommandTableProperty.h"

/**
 * Importer for SkillCommandTable.
 */
class SB_API FSBSkillCommandTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
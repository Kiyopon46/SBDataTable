#pragma once

#include "FSBDataTableImporter.h"
#include "SBSkillActiveStepTableProperty.h"

/**
 * Importer for SkillActiveStepTable.
 */
class SB_API FSBSkillActiveStepTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
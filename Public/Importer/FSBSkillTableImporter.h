#pragma once

#include "FSBDataTableImporter.h"
#include "SBSkillTableProperty.h"

/**
 * Importer for SkillTable.
 */
class SB_API FSBSkillTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
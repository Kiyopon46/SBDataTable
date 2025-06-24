#pragma once

#include "FSBDataTableImporter.h"
#include "SBSkillResultTableProperty.h"

/**
 * Importer for SkillResultTable.
 */
class SB_API FSBSkillResultTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
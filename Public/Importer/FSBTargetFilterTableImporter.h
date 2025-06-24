#pragma once

#include "FSBDataTableImporter.h"
#include "SBSkillTargetFilterTableProperty.h"

/**
 * Importer for TargetFilterTable.
 */
class SB_API FSBTargetFilterTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBPassiveSkillFunctionTableProperty.h"

/**
 * Importer for PassiveSkillFunctionTable.
 */
class SB_API FSBPassiveSkillFunctionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
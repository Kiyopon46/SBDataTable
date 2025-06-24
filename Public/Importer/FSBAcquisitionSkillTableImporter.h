#pragma once

#include "FSBDataTableImporter.h"
#include "SBAcquisitionSkillTableProperty.h"

/**
 * Importer for AcquisitionSkillTable.
 */
class SB_API FSBAcquisitionSkillTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
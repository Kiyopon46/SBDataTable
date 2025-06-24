#pragma once

#include "FSBDataTableImporter.h"
#include "SBConditionTriggerTableProperty.h"

/**
 * Importer for ConditionTriggerTable.
 */
class SB_API FSBConditionTriggerTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
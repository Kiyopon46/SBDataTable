#pragma once

#include "FSBDataTableImporter.h"
#include "SBUIActionRequestTableProperty.h"

/**
 * Importer for UIActionRequestTable.
 */
class SB_API FSBUIActionRequestTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
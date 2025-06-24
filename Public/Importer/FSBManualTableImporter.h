#pragma once

#include "FSBDataTableImporter.h"
#include "SBManualTableProperty.h"

/**
 * Importer for ManualTable.
 */
class SB_API FSBManualTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
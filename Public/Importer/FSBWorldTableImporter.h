#pragma once

#include "FSBDataTableImporter.h"
#include "SBWorldTableProperty.h"

/**
 * Importer for WorldTable.
 */
class SB_API FSBWorldTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBLevelTargetFilterTableProperty.h"

/**
 * Importer for LevelTargetFilter.
 */
class SB_API FSBLevelTargetFilterTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
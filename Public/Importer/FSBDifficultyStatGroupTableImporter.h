#pragma once

#include "FSBDataTableImporter.h"
#include "SBDifficultyStatGroupTableProperty.h"

/**
 * Importer for DifficultyStatGroupTable.
 */
class SB_API FSBDifficultyStatGroupTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
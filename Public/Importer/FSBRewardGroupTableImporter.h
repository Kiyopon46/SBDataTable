#pragma once

#include "FSBDataTableImporter.h"
#include "SBRewardGroupTableProperty.h"

/**
 * Importer for RewardGroupTable.
 */
class SB_API FSBRewardGroupTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
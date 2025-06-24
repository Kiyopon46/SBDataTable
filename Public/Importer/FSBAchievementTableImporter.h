#pragma once

#include "FSBDataTableImporter.h"
#include "SBAchievementTableProperty.h"

/**
 * Importer for AchievementTable.
 */
class SB_API FSBAchievementTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
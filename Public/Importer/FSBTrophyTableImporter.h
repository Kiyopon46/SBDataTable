#pragma once

#include "FSBDataTableImporter.h"
#include "SBTrophyTableProperty.h"

/**
 * Importer for TrophyTable.
 */
class SB_API FSBTrophyTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
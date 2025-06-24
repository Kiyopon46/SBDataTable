#pragma once

#include "FSBDataTableImporter.h"
#include "SBGearStatGroupTableProperty.h"

/**
 * Importer for GearStatGroupTable.
 */
class SB_API FSBGearStatGroupTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
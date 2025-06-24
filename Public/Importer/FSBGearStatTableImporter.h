#pragma once

#include "FSBDataTableImporter.h"
#include "SBGearStatTableProperty.h"

/**
 * Importer for GearStatTable.
 */
class SB_API FSBGearStatTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventTableProperty.h"

/**
 * Importer for ZoneEventTable.
 */
class SB_API FSBZoneEventTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBZonePhaseEventTableProperty.h"

/**
 * Importer for ZonePhaseEventTable.
 */
class SB_API FSBZonePhaseEventTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
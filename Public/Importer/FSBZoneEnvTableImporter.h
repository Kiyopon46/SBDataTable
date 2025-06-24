#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEnvTableProperty.h"

/**
 * Importer for ZoneEnvTable.
 */
class SB_API FSBZoneEnvTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
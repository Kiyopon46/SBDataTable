#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneLayerTableProperty.h"

/**
 * Importer for ZoneLayerTable.
 */
class SB_API FSBZoneLayerTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventZoneWarpTableProperty.h"

/**
 * Importer for EventZoneWarpTable.
 */
class SB_API FSBEventZoneWarpTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
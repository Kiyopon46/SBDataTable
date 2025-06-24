#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventTheaterTableProperty.h"

/**
 * Importer for EventTheaterTable.
 */
class SB_API FSBEventTheaterTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
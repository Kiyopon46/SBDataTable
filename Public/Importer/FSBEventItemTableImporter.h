#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventItemTableProperty.h"

/**
 * Importer for EventItemTable.
 */
class SB_API FSBEventItemTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
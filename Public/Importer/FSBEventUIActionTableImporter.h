#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventUIActionTableProperty.h"

/**
 * Importer for EventUIActionTable.
 */
class SB_API FSBEventUIActionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
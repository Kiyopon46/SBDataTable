#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneTriggerTableProperty.h"

/**
 * Importer for ZoneTriggerTable.
 */
class SB_API FSBZoneTriggerTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
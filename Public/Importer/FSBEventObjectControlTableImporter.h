#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventObjControl.h"

/**
 * Importer for EventObjectControlTable.
 */
class SB_API FSBEventObjectControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
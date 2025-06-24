#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventLaserControlTableProperty.h"

/**
 * Importer for EventLaserControlTable.
 */
class SB_API FSBEventLaserControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
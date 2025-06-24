#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventAreaControlVolumeControlTableProperty.h"

/**
 * Importer for EventAreaControlVolumeControlTable.
 */
class SB_API FSBEventAreaControlVolumeControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
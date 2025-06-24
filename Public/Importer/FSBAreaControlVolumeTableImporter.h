#pragma once

#include "FSBDataTableImporter.h"
#include "SBAreaControlVolumeTableProperty.h"

/**
 * Importer for AreaControlVolumeTable.
 */
class SB_API FSBAreaControlVolumeTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
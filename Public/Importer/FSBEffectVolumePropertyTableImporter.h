#pragma once

#include "FSBDataTableImporter.h"
#include "SBEffectVolumePropTableProperty.h"

/**
 * Importer for EffectVolumePropertyTable.
 */
class SB_API FSBEffectVolumePropertyTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
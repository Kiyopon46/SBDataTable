#pragma once

#include "FSBDataTableImporter.h"
#include "SBEffectVolumeTableProperty.h"

/**
 * Importer for EffectVolumeTable.
 */
class SB_API FSBEffectVolumeTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
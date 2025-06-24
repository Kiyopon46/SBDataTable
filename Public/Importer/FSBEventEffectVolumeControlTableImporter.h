#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventEffectVolumeControlTableProperty.h"

/**
 * Importer for EventEffectVolumeControlTable.
 */
class SB_API FSBEventEffectVolumeControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
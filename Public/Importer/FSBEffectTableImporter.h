#pragma once

#include "FSBDataTableImporter.h"
#include "SBEffectTableProperty.h"

/**
 * Importer for EffectTable.
 */
class SB_API FSBEffectTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
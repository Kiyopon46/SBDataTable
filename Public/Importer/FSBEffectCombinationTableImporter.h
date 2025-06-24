#pragma once

#include "FSBDataTableImporter.h"
#include "SBEffectCombinationTableProperty.h"

/**
 * Importer for EffectCombinationTable.
 */
class SB_API FSBEffectCombinationTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
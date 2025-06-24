#pragma once

#include "FSBDataTableImporter.h"
#include "SBMetaAITableProperty.h"

/**
 * Importer for MetaAITable.
 */
class SB_API FSBMetaAITableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
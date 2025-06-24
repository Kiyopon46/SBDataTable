#pragma once

#include "FSBDataTableImporter.h"
#include "SBResourceCacheSequenceTableProperty.h"

/**
 * Importer for ResourceCacheSequenceTable.
 */
class SB_API FSBResourceCacheSequenceTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
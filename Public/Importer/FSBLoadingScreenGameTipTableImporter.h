#pragma once

#include "FSBDataTableImporter.h"
#include "SBLoadingScreenGameTipTableProperty.h"

/**
 * Importer for LoadingScreenGameTipTable.
 */
class SB_API FSBLoadingScreenGameTipTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBGuideMessageTableProperty.h"

/**
 * Importer for GuideMessageTable.
 */
class SB_API FSBGuideMessageTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
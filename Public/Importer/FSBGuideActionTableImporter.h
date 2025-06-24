#pragma once

#include "FSBDataTableImporter.h"
#include "SBGuideActionTableProperty.h"

/**
 * Importer for GuideActionTable.
 */
class SB_API FSBGuideActionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
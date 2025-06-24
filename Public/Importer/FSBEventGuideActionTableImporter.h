#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventGuideActionTableProperty.h"

/**
 * Importer for EventGuideActionTable.
 */
class SB_API FSBEventGuideActionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
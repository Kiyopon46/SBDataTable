#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventItemActionTableProperty.h"

/**
 * Importer for EventItemActionTable.
 */
class SB_API FSBEventItemActionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
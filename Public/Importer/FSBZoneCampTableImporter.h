#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneCampTableProperty.h"

/**
 * Importer for ZoneCampTable.
 */
class SB_API FSBZoneCampTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
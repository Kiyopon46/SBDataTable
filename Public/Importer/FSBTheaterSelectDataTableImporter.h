#pragma once

#include "FSBDataTableImporter.h"
#include "SBTheaterSelectDataTableProperty.h"

/**
 * Importer for TheaterSelectDataTable.
 */
class SB_API FSBTheaterSelectDataTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
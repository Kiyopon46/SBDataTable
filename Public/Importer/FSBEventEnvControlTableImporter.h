#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventEnvControlTableProperty.h"

/**
 * Importer for EventEnvControlTable.
 */
class SB_API FSBEventEnvControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
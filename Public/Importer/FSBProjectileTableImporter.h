#pragma once

#include "FSBDataTableImporter.h"
#include "SBProjectileTableProperty.h"

/**
 * Importer for ProjectileTable.
 */
class SB_API FSBProjectileTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBLevelGraphicsOptionsTableProperty.h"

/**
 * Importer for LevelGraphicsOptions.
 */
class SB_API FSBLevelGraphicsOptionsTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
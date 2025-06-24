#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventSpawnTableProperty.h"

/**
 * Importer for EventSpawnTable.
 */
class SB_API FSBEventSpawnTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
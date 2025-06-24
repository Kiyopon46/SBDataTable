#pragma once

#include "FSBDataTableImporter.h"
#include "SBNGPlusZoneEventSpawnTableProperty.h"

/**
 * Importer for EventNewGamePlusSpawnTable.
 */
class SB_API FSBEventNewGamePlusSpawnTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
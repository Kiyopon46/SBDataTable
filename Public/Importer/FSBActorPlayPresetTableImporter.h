#pragma once

#include "FSBDataTableImporter.h"
#include "SBActorPlayPresetTableProperty.h"

/**
 * Importer for ActorPlayPresetTable.
 */
class SB_API FSBActorPlayPresetTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
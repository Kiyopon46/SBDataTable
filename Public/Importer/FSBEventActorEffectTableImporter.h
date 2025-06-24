#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventActorEffectTableProperty.h"

/**
 * Importer for EventActorEffectTable.
 */
class SB_API FSBEventActorEffectTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
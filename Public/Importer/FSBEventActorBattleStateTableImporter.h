#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventActorBattleStateTableProperty.h"

/**
 * Importer for EventActorBattleStateTable.
 */
class SB_API FSBEventActorBattleStateTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
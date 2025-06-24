#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventZoneEventActorControlTableProperty.h"

/**
 * Importer for EventZoneEventActorControlTable.
 */
class SB_API FSBEventZoneEventActorControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
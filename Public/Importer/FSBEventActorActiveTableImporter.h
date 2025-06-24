#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventActorActiveTableProperty.h"

/**
 * Importer for EventActorActiveTable.
 */
class SB_API FSBEventActorActiveTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
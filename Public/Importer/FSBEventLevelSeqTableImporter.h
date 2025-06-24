#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventLevelSeqTableProperty.h"

/**
 * Importer for EventLevelSeqTable.
 */
class SB_API FSBEventLevelSeqTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
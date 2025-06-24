#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventZoneControlTableProperty.h"

/**
 * Importer for EventZoneControlTable.
 */
class SB_API FSBEventZoneControlTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
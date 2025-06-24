#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventGiftTableProperty.h"

/**
 * Importer for EventGiftTable.
 */
class SB_API FSBEventGiftTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
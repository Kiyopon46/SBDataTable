#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventMetaAITableProperty.h"

/**
 * Importer for EventMetaAITable.
 */
class SB_API FSBEventMetaAITableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
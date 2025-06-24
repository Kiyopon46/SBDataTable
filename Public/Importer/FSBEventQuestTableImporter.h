#pragma once

#include "FSBDataTableImporter.h"
#include "SBEventQuestTableProperty.h"

/**
 * Importer for EventQuestTable.
 */
class SB_API FSBEventQuestTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBQuestTableProperty.h"

/**
 * Importer for QuestTable.
 */
class SB_API FSBQuestTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
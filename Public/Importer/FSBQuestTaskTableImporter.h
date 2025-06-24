#pragma once

#include "FSBDataTableImporter.h"
#include "SBQuestTaskTableProperty.h"

/**
 * Importer for QuestTaskTable.
 */
class SB_API FSBQuestTaskTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
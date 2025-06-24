#pragma once

#include "FSBDataTableImporter.h"
#include "SBQuestMissionTableProperty.h"

/**
 * Importer for QuestMissionTable.
 */
class SB_API FSBQuestMissionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
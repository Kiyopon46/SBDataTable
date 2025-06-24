#pragma once

#include "FSBDataTableImporter.h"
#include "SBCheatProgressQuestCommandsTableProperty.h"

/**
 * Importer for CheatProgressQuestCommandsTable.
 */
class SB_API FSBCheatProgressQuestCommandsTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
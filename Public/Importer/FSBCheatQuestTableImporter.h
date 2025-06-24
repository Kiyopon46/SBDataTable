#pragma once

#include "FSBDataTableImporter.h"
#include "SBCheatQuestTableProperty.h"

/**
 * Importer for CheatQuestTable.
 */
class SB_API FSBCheatQuestTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
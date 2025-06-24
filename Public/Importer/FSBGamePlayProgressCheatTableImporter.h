#pragma once

#include "FSBDataTableImporter.h"
#include "SBGamePlayProgressCheatTableProperty.h"

/**
 * Importer for GamePlayProgressCheatTable.
 */
class SB_API FSBGamePlayProgressCheatTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
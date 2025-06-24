#pragma once

#include "FSBDataTableImporter.h"
#include "SBGamePlayProgressRecordTableProperty.h"

/**
 * Importer for GamePlayProgressRecordTable.
 */
class SB_API FSBGamePlayProgressRecordTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
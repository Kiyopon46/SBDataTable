#pragma once

#include "FSBDataTableImporter.h"
#include "SBPuzzleStringArrayTableProperty.h"

/**
 * Importer for PuzzleStringArrayTable.
 */
class SB_API FSBPuzzleStringArrayTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
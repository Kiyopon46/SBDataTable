#pragma once

#include "FSBDataTableImporter.h"
#include "SBStudioTransitionTableProperty.h"

/**
 * Importer for StudioTransitionTable.
 */
class SB_API FSBStudioTransitionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
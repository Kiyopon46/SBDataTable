#pragma once

#include "FSBDataTableImporter.h"
#include "SBUITutorialTableProperty.h"

/**
 * Importer for UITutorialTable.
 */
class SB_API FSBUITutorialTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
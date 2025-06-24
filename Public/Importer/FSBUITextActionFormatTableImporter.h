#pragma once

#include "FSBDataTableImporter.h"
#include "SBUITextActionFormatTableProperty.h"

/**
 * Importer for UITextActionFormatTable.
 */
class SB_API FSBUITextActionFormatTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
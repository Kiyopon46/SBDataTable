#pragma once

#include "FSBDataTableImporter.h"
#include "SBUITextInputDefineProperty.h"

/**
 * Importer for UITextInputDefineTable.
 */
class SB_API FSBUITextInputDefineTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
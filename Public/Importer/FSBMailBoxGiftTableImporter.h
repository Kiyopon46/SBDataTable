#pragma once

#include "FSBDataTableImporter.h"
#include "SBMailBoxGiftTableProperty.h"

/**
 * Importer for MailBoxGiftTable.
 */
class SB_API FSBMailBoxGiftTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
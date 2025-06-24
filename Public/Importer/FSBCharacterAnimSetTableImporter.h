#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterAnimSetTableProperty.h"

/**
 * Importer for CharacterAnimSetTable.
 */
class SB_API FSBCharacterAnimSetTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterLevelTableProperty.h"

/**
 * Importer for CharacterLevelTable.
 */
class SB_API FSBCharacterLevelTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterTribeTableProperty.h"

/**
 * Importer for CharacterTribeTable.
 */
class SB_API FSBCharacterTribeTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
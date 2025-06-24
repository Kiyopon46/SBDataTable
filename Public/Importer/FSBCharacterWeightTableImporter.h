#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterWeightTableProperty.h"

/**
 * Importer for CharacterWeightTable.
 */
class SB_API FSBCharacterWeightTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
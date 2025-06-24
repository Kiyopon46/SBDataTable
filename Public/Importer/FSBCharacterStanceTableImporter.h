#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterStanceTableProperty.h"

/**
 * Importer for CharacterStanceTable.
 */
class SB_API FSBCharacterStanceTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterMoveTableProperty.h"

/**
 * Importer for CharacterMoveTable.
 */
class SB_API FSBCharacterMoveTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
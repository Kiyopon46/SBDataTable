#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterAnimMoveInfoTableProperty.h"

/**
 * Importer for CharacterAnimMoveInfoTable.
 */
class SB_API FSBCharacterAnimMoveInfoTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
#pragma once

#include "FSBDataTableImporter.h"
#include "SBNewGamePlusAlreadySetupTableProperty.h"

/**
 * Importer for NewGamePlusAlreadySetupTable.
 */
class SB_API FSBNewGamePlusAlreadySetupTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
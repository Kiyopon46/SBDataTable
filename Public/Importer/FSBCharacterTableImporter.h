#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterTableProperty.h"

/**
 * Importer for CharacterTable.
 */
class SB_API FSBCharacterTableImporter : public FSBDataTableImporter
{
public:
    virtual FSBMenuEntry GetMenuEntry() override;
    virtual FString GetPackagePath() const override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
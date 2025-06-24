#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterDetectAITableProperty.h"

/**
 * Importer for CharacterDetectAITable.
 */
class SB_API FSBCharacterDetectAITableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
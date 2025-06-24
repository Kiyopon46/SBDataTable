#pragma once

#include "FSBDataTableImporter.h"
#include "SBSoundEventLevelSequenceTableProperty.h"

/**
 * Importer for SoundEventLevelSequenceTable.
 */
class SB_API FSBSoundEventLevelSequenceTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
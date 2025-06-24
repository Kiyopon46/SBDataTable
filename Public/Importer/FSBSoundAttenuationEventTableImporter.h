#pragma once

#include "FSBDataTableImporter.h"
#include "SBSoundAttenuationEventTableProperty.h"

/**
 * Importer for SoundAttenuationEventTable.
 */
class SB_API FSBSoundAttenuationEventTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
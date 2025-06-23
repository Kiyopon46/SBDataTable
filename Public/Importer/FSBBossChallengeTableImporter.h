#pragma once

#include "FSBDataTableImporter.h"
#include "SBBossChallengeTableProperty.h"

/**
 * Importer for BossChallengeTable.
 */
class SB_API FSBBossChallengeTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
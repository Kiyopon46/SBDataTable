#pragma once

#include "FSBDataTableImporter.h"
#include "SBBossChallengeTableProperty.h"

/**
 * Importer for BossChallengeTable.
 */
class SB_API FSBBossChallengeTableImporter : public FSBDataTableImporter
{
public:
    virtual FSBMenuEntry GetMenuEntry() override;
    virtual FString GetPackagePath() const override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
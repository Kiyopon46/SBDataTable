#pragma once

#include "FSBDataTableImporter.h"
#include "SBActorStatTextTableProperty.h"

/**
 * Importer for ActorStatTextTable.
 */
class SB_API FSBActorStatTextTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
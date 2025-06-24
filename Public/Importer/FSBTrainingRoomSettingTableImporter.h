#pragma once

#include "FSBDataTableImporter.h"
#include "SBTrainningRoomSettingTableProperty.h"

/**
 * Importer for TrainingRoomSettingTable.
 */
class SB_API FSBTrainingRoomSettingTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
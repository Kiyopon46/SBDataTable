#pragma once

#include "FSBDataTableImporter.h"
#include "SBSoundEquipmentSetTableProperty.h"

/**
 * Importer for SoundEquipmentSetTable.
 */
class SB_API FSBSoundEquipmentSetTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
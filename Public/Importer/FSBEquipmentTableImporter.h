#pragma once

#include "FSBDataTableImporter.h"
#include "SBEquipmentTableProperty.h"

/**
 * Importer for EquipmentTable.
 */
class SB_API FSBEquipmentTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
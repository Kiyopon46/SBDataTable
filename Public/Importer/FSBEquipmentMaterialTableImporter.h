#pragma once

#include "FSBDataTableImporter.h"
#include "SBEquipmentMaterialTableProperty.h"

/**
 * Importer for EquipmentMaterialTable.
 */
class SB_API FSBEquipmentMaterialTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
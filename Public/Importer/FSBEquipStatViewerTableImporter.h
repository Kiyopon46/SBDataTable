#pragma once

#include "FSBDataTableImporter.h"
#include "SBEquipStatViewerTableProperty.h"

/**
 * Importer for EquipStatViewerTable.
 */
class SB_API FSBEquipStatViewerTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
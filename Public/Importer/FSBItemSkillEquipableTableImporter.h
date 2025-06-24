#pragma once

#include "FSBDataTableImporter.h"
#include "SBItemSkillEquipableTableProperty.h"

/**
 * Importer for ItemSkillEquipableTable.
 */
class SB_API FSBItemSkillEquipableTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
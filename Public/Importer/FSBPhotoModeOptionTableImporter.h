#pragma once

#include "FSBDataTableImporter.h"
#include "SBPhotoModeOptionTableProperty.h"

/**
 * Importer for PhotoModeOptionTable.
 */
class SB_API FSBPhotoModeOptionTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
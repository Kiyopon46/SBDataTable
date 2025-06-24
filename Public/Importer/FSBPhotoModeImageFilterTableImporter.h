#pragma once

#include "FSBDataTableImporter.h"
#include "SBPhotoModeImageFilterTableProperty.h"

/**
 * Importer for PhotoModeImageFilterTable.
 */
class SB_API FSBPhotoModeImageFilterTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
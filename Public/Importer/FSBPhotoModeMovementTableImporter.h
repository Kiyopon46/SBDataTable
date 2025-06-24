#pragma once

#include "FSBDataTableImporter.h"
#include "SBPhotoModeMovementTableProperty.h"

/**
 * Importer for PhotoModeMovementTable.
 */
class SB_API FSBPhotoModeMovementTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
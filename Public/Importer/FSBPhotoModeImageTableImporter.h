#pragma once

#include "FSBDataTableImporter.h"
#include "SBPhotoModeImageTableProperty.h"

/**
 * Importer for PhotoModeImageTable.
 */
class SB_API FSBPhotoModeImageTableImporter : public FSBDataTableImporter
{
public:
    virtual FSBMenuEntry GetMenuEntry() override;
    virtual FString GetPackagePath() const override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
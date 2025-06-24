#pragma once

#include "FSBDataTableImporter.h"
#include "SBPhotoModeFacialAnimationTableProperty.h"

/**
 * Importer for PhotoModeFacialAnimationTable.
 */
class SB_API FSBPhotoModeFacialAnimationTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
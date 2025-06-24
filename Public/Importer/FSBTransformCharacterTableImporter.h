#pragma once

#include "FSBDataTableImporter.h"
#include "SBTransformCharacterTableProperty.h"

/**
 * Importer for TransformCharacterTable.
 */
class SB_API FSBTransformCharacterTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
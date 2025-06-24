#pragma once

#include "FSBDataTableImporter.h"
#include "SBZoneEventAIDecoTableProperty.h"

/**
 * Importer for EventAIDecoratorTable.
 */
class SB_API FSBEventAIDecoratorTableImporter : public FSBDataTableImporter
{
public:
    virtual FString GetDataTableName() const override;
    virtual TFunction<void()> GetMenuCallback() override;
    virtual UScriptStruct* GetRowStruct() const override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
};
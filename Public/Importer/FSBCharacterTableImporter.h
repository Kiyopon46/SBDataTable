#pragma once

#include "FSBDataTableImporter.h"
#include "SBCharacterTableProperty.h"

class FSBCharacterTableImporter : public FSBDataTableImporter
{
public:
//    virtual TSharedPtr<FJsonObject> LoadJsonRows(const FString& FilePath) override;
    virtual void PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& RowsObject) override;
    virtual FString GetPackagePath() const override;
    virtual UScriptStruct* GetRowStruct() const override;
};
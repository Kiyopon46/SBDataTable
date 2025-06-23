#pragma once

#include "FSBDataTableImporter.h"

class SB_API FSBDataTableImporterFactory
{
public:
	TArray<TPair<FString, TSharedPtr<FSBDataTableImporter>>> GetImporterMapSortedByName() const;
};

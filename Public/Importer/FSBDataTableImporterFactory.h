#pragma once

#include "FSBDataTableImporter.h"

class SB_API FSBDataTableImporterFactory
{
public:
	TArray<TSharedPtr<FSBDataTableImporter>> GetInstanceArray() const;
};

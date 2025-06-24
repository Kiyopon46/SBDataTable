#pragma once

#include "FSBDataTableImporter.h"

class SB_API FSBDataTableImporterFactory
{
public:
	void RegisterAll() const;
	TArray<TPair<FString, TSharedPtr<FSBDataTableImporter>>> GetImporterMapSortedByName() const;

	TSharedPtr<FSBDataTableImporter> GetImporterFor(const TSharedPtr<FJsonObject>& Json);

private:
	static TArray<TSharedPtr<FSBDataTableImporter>> GImporterList;
	static TMap<FName, TSharedPtr<FSBDataTableImporter>> ImporterMap;
};

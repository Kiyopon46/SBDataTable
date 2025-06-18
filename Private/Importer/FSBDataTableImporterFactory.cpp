#include "Importer/FSBDataTableImporterFactory.h"

#include "Importer/FSBCharacterTableImporter.h" // SBCharacterTableProperty
#include "Importer/FSBPhotoModeImageTableImporter.h" // SBPhotoModeImageTableProperty

// どこかに保持（Editorモジュールなど）
static TArray<TSharedPtr<FSBDataTableImporter>> GImporterList;

TArray<TSharedPtr<FSBDataTableImporter>> FSBDataTableImporterFactory::GetInstanceArray() const
{
	TArray<TSharedPtr<FSBDataTableImporter>> Result;

	TSharedPtr<FSBDataTableImporter> Importer1 = MakeShared<FSBCharacterTableImporter>();
	TSharedPtr<FSBDataTableImporter> Importer2 = MakeShared<FSBPhotoModeImageTableImporter>();

	GImporterList.Add(Importer1);
	GImporterList.Add(Importer2);

	Result.Add(Importer1);
	Result.Add(Importer2);

	return Result;
}
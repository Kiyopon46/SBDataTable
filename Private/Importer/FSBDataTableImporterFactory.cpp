#include "Importer/FSBDataTableImporterFactory.h"

#include "Importer/FSBCharacterTableImporter.h" // SBCharacterTableProperty
#include "Importer/FSBPhotoModeImageTableImporter.h" // SBPhotoModeImageTableProperty
#include "Importer/FSBBossChallengeTableImporter.h" // SBBossChallengeTableProperty

// どこかに保持（Editorモジュールなど）
static TArray<TSharedPtr<FSBDataTableImporter>> GImporterList;

TArray<TSharedPtr<FSBDataTableImporter>> FSBDataTableImporterFactory::GetInstanceArray() const
{
	TArray<TSharedPtr<FSBDataTableImporter>> Result;

	TSharedPtr<FSBDataTableImporter> Importer1 = MakeShared<FSBCharacterTableImporter>();
	TSharedPtr<FSBDataTableImporter> Importer2 = MakeShared<FSBPhotoModeImageTableImporter>();
	TSharedPtr<FSBDataTableImporter> Importer3 = MakeShared<FSBBossChallengeTableImporter>();

	GImporterList.Add(Importer1);
	GImporterList.Add(Importer2);
	GImporterList.Add(Importer3);

	Result.Add(Importer1);
	Result.Add(Importer2);
	Result.Add(Importer3);

	return Result;
}
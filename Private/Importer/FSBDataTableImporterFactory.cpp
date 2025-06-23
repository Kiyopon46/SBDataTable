#include "Importer/FSBDataTableImporterFactory.h"

#include "Importer/FSBCharacterTableImporter.h" // SBCharacterTableProperty
#include "Importer/FSBPhotoModeImageTableImporter.h" // SBPhotoModeImageTableProperty
#include "Importer/FSBBossChallengeTableImporter.h" // SBBossChallengeTableProperty

// どこかに保持（Editorモジュールなど）
static TArray<TSharedPtr<FSBDataTableImporter>> GImporterList;

TArray<TPair<FString, TSharedPtr<FSBDataTableImporter>>> FSBDataTableImporterFactory::GetImporterMapSortedByName() const
{
	TArray<TPair<FString, TSharedPtr<FSBDataTableImporter>>> Result;

	GImporterList.Add(MakeShared<FSBCharacterTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeImageTableImporter>());
	GImporterList.Add(MakeShared<FSBBossChallengeTableImporter>());

	for (const TSharedPtr<FSBDataTableImporter>& Importer : GImporterList)
	{
		const FString TableName = Importer->GetDataTableName();
		Result.Add(TPair<FString, TSharedPtr<FSBDataTableImporter>>(TableName, Importer));
	}

	// DataTable名順でソート
	Result.Sort([](const TPair<FString, TSharedPtr<FSBDataTableImporter>>& A,
		const TPair<FString, TSharedPtr<FSBDataTableImporter>>& B)
		{
			return A.Key < B.Key;
		});

	return Result;
}
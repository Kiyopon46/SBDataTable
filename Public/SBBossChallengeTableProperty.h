#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBBossChallengeTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBBossChallengeTableProperty : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString StageGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 StagePriority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ZoneAlias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SpawnPointAlias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> UnlockAchievementArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> UnlockEntitlementArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> EnemyEventSpawnList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MaximumPresetAlias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MaximumNewGamePlusPresetAlias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MinimumPresetAlias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MaximumPresetAliasStoryMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MaximumNewGamePlusPresetAliasStoryMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MinimumPresetAliasStoryMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MaximumPresetAliasHardMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MaximumNewGamePlusPresetAliasHardMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString MinimumPresetAliasHardMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString BossStringKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString RegionStringKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ThumbnailImagePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ThumbnailIconImagePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> ResourceCacheCharacterAliases;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString FileSuffix;

};
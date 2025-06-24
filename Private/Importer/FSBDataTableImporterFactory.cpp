#include "Importer/FSBDataTableImporterFactory.h"

#include "Importer/FSBAchievementTableImporter.h"
#include "Importer/FSBAcquisitionSkillTableImporter.h"
#include "Importer/FSBActivityTableImporter.h"
#include "Importer/FSBActorPlayPresetTableImporter.h"
#include "Importer/FSBActorStatTextTableImporter.h"
#include "Importer/FSBAIGroupTableImporter.h"
#include "Importer/FSBAlbumTableImporter.h"
#include "Importer/FSBAreaControlVolumeTableImporter.h"
#include "Importer/FSBArtBookTableImporter.h"
#include "Importer/FSBBossChallengeTableImporter.h"
#include "Importer/FSBCanTableImporter.h"
#include "Importer/FSBCharacterAnimMoveInfoTableImporter.h"
#include "Importer/FSBCharacterAnimSetTableImporter.h"
#include "Importer/FSBCharacterAppearanceTableImporter.h"
#include "Importer/FSBCharacterDeadTableImporter.h"
#include "Importer/FSBCharacterDetectAITableImporter.h"
#include "Importer/FSBCharacterLevelTableImporter.h"
#include "Importer/FSBCharacterMoveTableImporter.h"
#include "Importer/FSBCharacterStanceTableImporter.h"
#include "Importer/FSBCharacterTableImporter.h"
#include "Importer/FSBCharacterTribeTableImporter.h"
#include "Importer/FSBCharacterWeightTableImporter.h"
#include "Importer/FSBCheatCommandTableImporter.h"
#include "Importer/FSBCheatProgressQuestCommandsTableImporter.h"
#include "Importer/FSBCheatQuestTableImporter.h"
#include "Importer/FSBConditionGroupTableImporter.h"
#include "Importer/FSBConditionTableImporter.h"
#include "Importer/FSBConditionTriggerTableImporter.h"
#include "Importer/FSBCreditTableImporter.h"
#include "Importer/FSBDifficultyStatGroupTableImporter.h"
#include "Importer/FSBDropRateAdjustTableImporter.h"
#include "Importer/FSBEditorTooltipTableImporter.h"
#include "Importer/FSBEffectCombinationTableImporter.h"
#include "Importer/FSBEffectTableImporter.h"
#include "Importer/FSBEffectVolumePropertyTableImporter.h"
#include "Importer/FSBEffectVolumeTableImporter.h"
#include "Importer/FSBEquipmentMaterialTableImporter.h"
#include "Importer/FSBEquipmentTableImporter.h"
#include "Importer/FSBEquipStatViewerTableImporter.h"
#include "Importer/FSBEventActorActiveTableImporter.h"
#include "Importer/FSBEventActorBattleStateTableImporter.h"
#include "Importer/FSBEventActorEffectTableImporter.h"
#include "Importer/FSBEventAIDecoratorTableImporter.h"
#include "Importer/FSBEventAreaControlVolumeControlTableImporter.h"
#include "Importer/FSBEventEffectVolumeControlTableImporter.h"
#include "Importer/FSBEventEnvControlTableImporter.h"
#include "Importer/FSBEventGiftTableImporter.h"
#include "Importer/FSBEventGuideActionTableImporter.h"
#include "Importer/FSBEventInteractCampTableImporter.h"
#include "Importer/FSBEventItemActionTableImporter.h"
#include "Importer/FSBEventItemTableImporter.h"
#include "Importer/FSBEventLaserControlTableImporter.h"
#include "Importer/FSBEventLevelSeqTableImporter.h"
#include "Importer/FSBEventMetaAITableImporter.h"
#include "Importer/FSBEventNewGamePlusSpawnTableImporter.h"
#include "Importer/FSBEventObjectControlTableImporter.h"
#include "Importer/FSBEventQuestTableImporter.h"
#include "Importer/FSBEventRequestPathWayTableImporter.h"
#include "Importer/FSBEventSpawnTableImporter.h"
#include "Importer/FSBEventTheaterTableImporter.h"
#include "Importer/FSBEventUIActionTableImporter.h"
#include "Importer/FSBEventZoneControlTableImporter.h"
#include "Importer/FSBEventZoneEventActorControlTableImporter.h"
#include "Importer/FSBEventZoneWarpTableImporter.h"
#include "Importer/FSBGamePlayProgressCheatTableImporter.h"
#include "Importer/FSBGamePlayProgressRecordTableImporter.h"
#include "Importer/FSBGearStatGroupTableImporter.h"
#include "Importer/FSBGearStatTableImporter.h"
#include "Importer/FSBGuideActionTableImporter.h"
#include "Importer/FSBGuideMessageTableImporter.h"
#include "Importer/FSBHintTableImporter.h"
#include "Importer/FSBIsolatedAreaTableImporter.h"
#include "Importer/FSBItemBulletTableImporter.h"
#include "Importer/FSBItemConsumableTableImporter.h"
#include "Importer/FSBItemEquipableTableImporter.h"
#include "Importer/FSBItemFishTableImporter.h"
#include "Importer/FSBItemLureTableImporter.h"
#include "Importer/FSBItemReplacementTableImporter.h"
#include "Importer/FSBItemSkillEquipableTableImporter.h"
#include "Importer/FSBItemSpawnTableImporter.h"
#include "Importer/FSBItemTableImporter.h"
#include "Importer/FSBKeyMappingRolloverTableImporter.h"
#include "Importer/FSBKeyMappingTableImporter.h"
#include "Importer/FSBLevelGraphicsOptionsTableImporter.h"
#include "Importer/FSBLevelTargetFilterTableImporter.h"
#include "Importer/FSBLoadingScreenGameTipTableImporter.h"
#include "Importer/FSBMailBoxGiftTableImporter.h"
#include "Importer/FSBManualTableImporter.h"
#include "Importer/FSBMetaAIBehaviorTableImporter.h"
#include "Importer/FSBMetaAITableImporter.h"
#include "Importer/FSBMultiMapTableImporter.h"
#include "Importer/FSBMultiPlayRuleTableImporter.h"
#include "Importer/FSBNewGamePlusAlreadySetupTableImporter.h"
#include "Importer/FSBNikkeLostArticleTableImporter.h"
#include "Importer/FSBNikkeStageTableImporter.h"
#include "Importer/FSBPassiveSkillFunctionTableImporter.h"
#include "Importer/FSBPhotoChallengeTableImporter.h"
#include "Importer/FSBPhotoModeEyesPositionByPoseTableImporter.h"
#include "Importer/FSBPhotoModeFacialAnimationTableImporter.h"
#include "Importer/FSBPhotoModeImageFilterTableImporter.h"
#include "Importer/FSBPhotoModeImageTableImporter.h"
#include "Importer/FSBPhotoModeMovementTableImporter.h"
#include "Importer/FSBPhotoModeOptionTableImporter.h"
#include "Importer/FSBProjectileTableImporter.h"
#include "Importer/FSBPuzzleStringArrayTableImporter.h"
#include "Importer/FSBQuestMissionTableImporter.h"
#include "Importer/FSBQuestTableImporter.h"
#include "Importer/FSBQuestTaskGroupTableImporter.h"
#include "Importer/FSBQuestTaskTableImporter.h"
#include "Importer/FSBResourceCacheSequenceTableImporter.h"
#include "Importer/FSBRestartRuleTableImporter.h"
#include "Importer/FSBRewardGroupTableImporter.h"
#include "Importer/FSBSequenceActorTagTableImporter.h"
#include "Importer/FSBShopItemTableImporter.h"
#include "Importer/FSBShopTableImporter.h"
#include "Importer/FSBShowParamTableImporter.h"
#include "Importer/FSBSkillActiveStepTableImporter.h"
#include "Importer/FSBSkillCommandTableImporter.h"
#include "Importer/FSBSkillPriorityTableImporter.h"
#include "Importer/FSBSkillResultTableImporter.h"
#include "Importer/FSBSkillTableImporter.h"
#include "Importer/FSBSocialAnimTableImporter.h"
#include "Importer/FSBSoundAttenuationEventTableImporter.h"
#include "Importer/FSBSoundEquipmentSetTableImporter.h"
#include "Importer/FSBSoundEventLevelSequenceTableImporter.h"
#include "Importer/FSBSoundEventQuestTableImporter.h"
#include "Importer/FSBSoundEventTableImporter.h"
#include "Importer/FSBSpawnGroupRuleTableImporter.h"
#include "Importer/FSBSPLevelTableImporter.h"
#include "Importer/FSBStudioTransitionTableImporter.h"
#include "Importer/FSBTargetFilterTableImporter.h"
#include "Importer/FSBTheaterSelectDataTableImporter.h"
#include "Importer/FSBTrainingRoomSettingTableImporter.h"
#include "Importer/FSBTransformCharacterTableImporter.h"
#include "Importer/FSBTrophyTableImporter.h"
#include "Importer/FSBTurntableSoundTableImporter.h"
#include "Importer/FSBUIActionRequestTableImporter.h"
#include "Importer/FSBUIKeyImageAssetTableImporter.h"
#include "Importer/FSBUITextActionFormatTableImporter.h"
#include "Importer/FSBUITextInputDefineTableImporter.h"
#include "Importer/FSBUITutorialTableImporter.h"
#include "Importer/FSBWorldMapTableImporter.h"
#include "Importer/FSBWorldTableImporter.h"
#include "Importer/FSBWorldTransitionTableImporter.h"
#include "Importer/FSBZoneCampTableImporter.h"
#include "Importer/FSBZoneEnvSpawnTableImporter.h"
#include "Importer/FSBZoneEnvTableImporter.h"
#include "Importer/FSBZoneEventActorTableImporter.h"
#include "Importer/FSBZoneEventTableImporter.h"
#include "Importer/FSBZoneLayerTableImporter.h"
#include "Importer/FSBZonePhaseEventTableImporter.h"
#include "Importer/FSBZoneTableImporter.h"
#include "Importer/FSBZoneTriggerTableImporter.h"

// どこかに保持（Editorモジュールなど）
TArray<TSharedPtr<FSBDataTableImporter>> FSBDataTableImporterFactory::GImporterList;

TMap<FName, TSharedPtr<FSBDataTableImporter>> FSBDataTableImporterFactory::ImporterMap;

void FSBDataTableImporterFactory::RegisterAll() const
{
	// if registered, do nothing.
	if (FSBDataTableImporterFactory::ImporterMap.Num() > 0)
	{
		return;
	}

	GImporterList.Add(MakeShared<FSBAchievementTableImporter>());
	GImporterList.Add(MakeShared<FSBAcquisitionSkillTableImporter>());
	GImporterList.Add(MakeShared<FSBActivityTableImporter>());
	GImporterList.Add(MakeShared<FSBActorPlayPresetTableImporter>());
	GImporterList.Add(MakeShared<FSBActorStatTextTableImporter>());
	GImporterList.Add(MakeShared<FSBAIGroupTableImporter>());
	GImporterList.Add(MakeShared<FSBAlbumTableImporter>());
	GImporterList.Add(MakeShared<FSBAreaControlVolumeTableImporter>());
	GImporterList.Add(MakeShared<FSBArtBookTableImporter>());
	GImporterList.Add(MakeShared<FSBBossChallengeTableImporter>());
	GImporterList.Add(MakeShared<FSBCanTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterAnimMoveInfoTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterAnimSetTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterAppearanceTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterDeadTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterDetectAITableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterLevelTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterMoveTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterStanceTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterTribeTableImporter>());
	GImporterList.Add(MakeShared<FSBCharacterWeightTableImporter>());
	GImporterList.Add(MakeShared<FSBCheatCommandTableImporter>());
	GImporterList.Add(MakeShared<FSBCheatProgressQuestCommandsTableImporter>());
	GImporterList.Add(MakeShared<FSBCheatQuestTableImporter>());
	GImporterList.Add(MakeShared<FSBConditionGroupTableImporter>());
	GImporterList.Add(MakeShared<FSBConditionTableImporter>());
	GImporterList.Add(MakeShared<FSBConditionTriggerTableImporter>());
	GImporterList.Add(MakeShared<FSBCreditTableImporter>());
	GImporterList.Add(MakeShared<FSBDifficultyStatGroupTableImporter>());
	GImporterList.Add(MakeShared<FSBDropRateAdjustTableImporter>());
	GImporterList.Add(MakeShared<FSBEditorTooltipTableImporter>());
	GImporterList.Add(MakeShared<FSBEffectCombinationTableImporter>());
	GImporterList.Add(MakeShared<FSBEffectTableImporter>());
	GImporterList.Add(MakeShared<FSBEffectVolumePropertyTableImporter>());
	GImporterList.Add(MakeShared<FSBEffectVolumeTableImporter>());
	GImporterList.Add(MakeShared<FSBEquipmentMaterialTableImporter>());
	GImporterList.Add(MakeShared<FSBEquipmentTableImporter>());
	GImporterList.Add(MakeShared<FSBEquipStatViewerTableImporter>());
	GImporterList.Add(MakeShared<FSBEventActorActiveTableImporter>());
	GImporterList.Add(MakeShared<FSBEventActorBattleStateTableImporter>());
	GImporterList.Add(MakeShared<FSBEventActorEffectTableImporter>());
	GImporterList.Add(MakeShared<FSBEventAIDecoratorTableImporter>());
	GImporterList.Add(MakeShared<FSBEventAreaControlVolumeControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventEffectVolumeControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventEnvControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventGiftTableImporter>());
	GImporterList.Add(MakeShared<FSBEventGuideActionTableImporter>());
	GImporterList.Add(MakeShared<FSBEventInteractCampTableImporter>());
	GImporterList.Add(MakeShared<FSBEventItemActionTableImporter>());
	GImporterList.Add(MakeShared<FSBEventItemTableImporter>());
	GImporterList.Add(MakeShared<FSBEventLaserControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventLevelSeqTableImporter>());
	GImporterList.Add(MakeShared<FSBEventMetaAITableImporter>());
	GImporterList.Add(MakeShared<FSBEventNewGamePlusSpawnTableImporter>());
	GImporterList.Add(MakeShared<FSBEventObjectControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventQuestTableImporter>());
	GImporterList.Add(MakeShared<FSBEventRequestPathWayTableImporter>());
	GImporterList.Add(MakeShared<FSBEventSpawnTableImporter>());
	GImporterList.Add(MakeShared<FSBEventTheaterTableImporter>());
	GImporterList.Add(MakeShared<FSBEventUIActionTableImporter>());
	GImporterList.Add(MakeShared<FSBEventZoneControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventZoneEventActorControlTableImporter>());
	GImporterList.Add(MakeShared<FSBEventZoneWarpTableImporter>());
	GImporterList.Add(MakeShared<FSBGamePlayProgressCheatTableImporter>());
	GImporterList.Add(MakeShared<FSBGamePlayProgressRecordTableImporter>());
	GImporterList.Add(MakeShared<FSBGearStatGroupTableImporter>());
	GImporterList.Add(MakeShared<FSBGearStatTableImporter>());
	GImporterList.Add(MakeShared<FSBGuideActionTableImporter>());
	GImporterList.Add(MakeShared<FSBGuideMessageTableImporter>());
	GImporterList.Add(MakeShared<FSBHintTableImporter>());
	GImporterList.Add(MakeShared<FSBIsolatedAreaTableImporter>());
	GImporterList.Add(MakeShared<FSBItemBulletTableImporter>());
	GImporterList.Add(MakeShared<FSBItemConsumableTableImporter>());
	GImporterList.Add(MakeShared<FSBItemEquipableTableImporter>());
	GImporterList.Add(MakeShared<FSBItemFishTableImporter>());
	GImporterList.Add(MakeShared<FSBItemLureTableImporter>());
	GImporterList.Add(MakeShared<FSBItemReplacementTableImporter>());
	GImporterList.Add(MakeShared<FSBItemSkillEquipableTableImporter>());
	GImporterList.Add(MakeShared<FSBItemSpawnTableImporter>());
	GImporterList.Add(MakeShared<FSBItemTableImporter>());
	GImporterList.Add(MakeShared<FSBKeyMappingRolloverTableImporter>());
	GImporterList.Add(MakeShared<FSBKeyMappingTableImporter>());
	GImporterList.Add(MakeShared<FSBLevelGraphicsOptionsTableImporter>());
	GImporterList.Add(MakeShared<FSBLevelTargetFilterTableImporter>());
	GImporterList.Add(MakeShared<FSBLoadingScreenGameTipTableImporter>());
	GImporterList.Add(MakeShared<FSBMailBoxGiftTableImporter>());
	GImporterList.Add(MakeShared<FSBManualTableImporter>());
	GImporterList.Add(MakeShared<FSBMetaAIBehaviorTableImporter>());
	GImporterList.Add(MakeShared<FSBMetaAITableImporter>());
	GImporterList.Add(MakeShared<FSBMultiMapTableImporter>());
	GImporterList.Add(MakeShared<FSBMultiPlayRuleTableImporter>());
	GImporterList.Add(MakeShared<FSBNewGamePlusAlreadySetupTableImporter>());
	GImporterList.Add(MakeShared<FSBNikkeLostArticleTableImporter>());
	GImporterList.Add(MakeShared<FSBNikkeStageTableImporter>());
	GImporterList.Add(MakeShared<FSBPassiveSkillFunctionTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoChallengeTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeEyesPositionByPoseTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeFacialAnimationTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeImageFilterTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeImageTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeMovementTableImporter>());
	GImporterList.Add(MakeShared<FSBPhotoModeOptionTableImporter>());
	GImporterList.Add(MakeShared<FSBProjectileTableImporter>());
	GImporterList.Add(MakeShared<FSBPuzzleStringArrayTableImporter>());
	GImporterList.Add(MakeShared<FSBQuestMissionTableImporter>());
	GImporterList.Add(MakeShared<FSBQuestTableImporter>());
	GImporterList.Add(MakeShared<FSBQuestTaskGroupTableImporter>());
	GImporterList.Add(MakeShared<FSBQuestTaskTableImporter>());
	GImporterList.Add(MakeShared<FSBResourceCacheSequenceTableImporter>());
	GImporterList.Add(MakeShared<FSBRestartRuleTableImporter>());
	GImporterList.Add(MakeShared<FSBRewardGroupTableImporter>());
	GImporterList.Add(MakeShared<FSBSequenceActorTagTableImporter>());
	GImporterList.Add(MakeShared<FSBShopItemTableImporter>());
	GImporterList.Add(MakeShared<FSBShopTableImporter>());
	GImporterList.Add(MakeShared<FSBShowParamTableImporter>());
	GImporterList.Add(MakeShared<FSBSkillActiveStepTableImporter>());
	GImporterList.Add(MakeShared<FSBSkillCommandTableImporter>());
	GImporterList.Add(MakeShared<FSBSkillPriorityTableImporter>());
	GImporterList.Add(MakeShared<FSBSkillResultTableImporter>());
	GImporterList.Add(MakeShared<FSBSkillTableImporter>());
	GImporterList.Add(MakeShared<FSBSocialAnimTableImporter>());
	GImporterList.Add(MakeShared<FSBSoundAttenuationEventTableImporter>());
	GImporterList.Add(MakeShared<FSBSoundEquipmentSetTableImporter>());
	GImporterList.Add(MakeShared<FSBSoundEventLevelSequenceTableImporter>());
	GImporterList.Add(MakeShared<FSBSoundEventQuestTableImporter>());
	GImporterList.Add(MakeShared<FSBSoundEventTableImporter>());
	GImporterList.Add(MakeShared<FSBSpawnGroupRuleTableImporter>());
	GImporterList.Add(MakeShared<FSBSPLevelTableImporter>());
	GImporterList.Add(MakeShared<FSBStudioTransitionTableImporter>());
	GImporterList.Add(MakeShared<FSBTargetFilterTableImporter>());
	GImporterList.Add(MakeShared<FSBTheaterSelectDataTableImporter>());
	GImporterList.Add(MakeShared<FSBTrainingRoomSettingTableImporter>());
	GImporterList.Add(MakeShared<FSBTransformCharacterTableImporter>());
	GImporterList.Add(MakeShared<FSBTrophyTableImporter>());
	GImporterList.Add(MakeShared<FSBTurntableSoundTableImporter>());
	GImporterList.Add(MakeShared<FSBUIActionRequestTableImporter>());
	GImporterList.Add(MakeShared<FSBUIKeyImageAssetTableImporter>());
	GImporterList.Add(MakeShared<FSBUITextActionFormatTableImporter>());
	GImporterList.Add(MakeShared<FSBUITextInputDefineTableImporter>());
	GImporterList.Add(MakeShared<FSBUITutorialTableImporter>());
	GImporterList.Add(MakeShared<FSBWorldMapTableImporter>());
	GImporterList.Add(MakeShared<FSBWorldTableImporter>());
	GImporterList.Add(MakeShared<FSBWorldTransitionTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneCampTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneEnvSpawnTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneEnvTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneEventActorTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneEventTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneLayerTableImporter>());
	GImporterList.Add(MakeShared<FSBZonePhaseEventTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneTableImporter>());
	GImporterList.Add(MakeShared<FSBZoneTriggerTableImporter>());

	for (const TSharedPtr<FSBDataTableImporter>& Importer : GImporterList)
	{
		const FString TableName = Importer->GetDataTableName();
		FSBDataTableImporterFactory::ImporterMap.Add(FName(TableName), Importer);
	}
}

TSharedPtr<FSBDataTableImporter> FSBDataTableImporterFactory::GetImporterFor(const TSharedPtr<FJsonObject>& Json)
{
	FString TableNameStr;
	if (!Json->TryGetStringField(TEXT("Name"), TableNameStr))
	{
		return nullptr;
	}

	FName TableName(*TableNameStr);
	if (FSBDataTableImporterFactory::ImporterMap.Contains(TableName))
	{
		return FSBDataTableImporterFactory::ImporterMap[TableName];
	}

	return nullptr;
}

TArray<TPair<FString, TSharedPtr<FSBDataTableImporter>>> FSBDataTableImporterFactory::GetImporterMapSortedByName() const
{
	// if not registered, do register.
	if (FSBDataTableImporterFactory::ImporterMap.Num() <= 0)
	{
		RegisterAll();
	}

	TArray<TPair<FString, TSharedPtr<FSBDataTableImporter>>> Result;

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
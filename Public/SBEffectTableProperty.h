#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBEffectTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBEffectTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Flag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DispelFlagsArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> Tags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OverrideTribe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectGroupName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectAttributeType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectAttackType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionDelay_Jump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionDelay_Swimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionDelay_Down;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionDelay_Airborne;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionDelay_KnockBack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ConditionActive_ChancePercent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_Swimming;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_UnderWater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_Airborne;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_Jump;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_BattleMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_TargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActiveActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActiveActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActiveActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_DeactiveActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_DeactiveActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_DeactiveActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActorType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActorType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActorType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActorStat1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ActorStatCheck1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConditionActive_ActorStatCheckValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ConditionActive_MinAngleFromConstructor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ConditionActive_MaxAngleFromConstructor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckNoneEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ConstructorActorAcquisitionAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_DeactiveConstructorActorAcquisitionAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_MainActorAcquisitionAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_DeactiveMainActorAcquisitionAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_ActiveTribe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_DeactiveTribe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckCharacterRankArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckNoneCharacterRankArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckCharacterFlagAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckNoneCharacterFlagAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_CheckEffectSkillFlagArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_ConstructorEffectActiveTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionActive_ConstructorEffectDeactiveTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_SkillHitResult;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_StoryMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_EventMove;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionActive_ItemCompare;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConditionActive_ItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatSecondCategory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StatCalculationTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CalculationValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CalculationValueRandomMin;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CalculationValueRandomMax;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CalculationMultipleWhenBacksideHit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float CalculationMultipleValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAdditionalCalculationWithShield;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAdditionalCalculationWithCritical;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAdditionalCalculationWithAttribute;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAdditionalCalculationWithRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAdditionalCalculationWithWeakPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDrainHpByAttack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBetaGaugeEventByDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bTachyGaugeEventByDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bNotGainTachyGaugeByDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bNotVisibleHPBarWhenDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStatRestore;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Overlap;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 OverlapCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LifeType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LifeTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LoopIntervalTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FixedTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveTargetEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveTargetResultShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bActiveTargetApplyConditionHitMe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LoopTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LoopTargetEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LoopTargetResultShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLoopTargetApplyConditionHitMe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FixedTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DeactiveTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeactiveTargetEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DeactiveTargetResultShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bDeactiveTargetApplyConditionHitMe;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AvailableJustEvade;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bKeepPlayedShowWhenDeactive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LoopShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DeactiveShowPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CollisionBPPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ChainEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TargetChainEffectAliasWhenZeroShieldArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StanceAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveAttackedCollisionGroupArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorState10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DelayActorState10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionValue4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionValue5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttackedCollisionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AttackedCollisionGroupResultType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ImmuneEffectGroupArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseGetupMoveAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionEnd5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveStanceAnimType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableSave;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPlayOnDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStopOnRevival;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bWarpToSafeLocationOnDead;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WarpToSafeLocationEffectAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIgnoreTimeScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAggroToConstructorActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetDeadType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoundDecibel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SoundLife;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionChainType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionChainSelfEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ConditionChainTargetEffectAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseCreateEffectPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectStartPosition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCreateEffectPositionOnGround;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EffectPositionOnGroundCheckDistance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectRelativeLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectLocationRandomRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectRelativeAxisType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectRelativeRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CreateEffectRotationRandomRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bShowEffectTimeUI;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Loc_EffectTimeUIText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EffectUIType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionFromAcquisitionAlias5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionType5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ExpansionValue5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ShowKeyTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool LoopElement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ElementTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ElementType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ElementAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bProjectileAttackPossible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ProjectileAttackDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveProjectileTargetFilterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActiveProjectileAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPauseWhenAttachLevelSequence;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPauseWhenPlayerAttachLevelSequence;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActionAssistTargetFilter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActionAssistCheckDelay;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ActionAssistActiveTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
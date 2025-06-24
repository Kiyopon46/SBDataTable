#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneEventTheaterTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneEventTheaterTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TheaterAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TheaterAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelSeqAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ControlType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SequencePlayTransformType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SequencePlayTransformCastType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString BindTargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BindTargetStartFadeOutKeepDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float BindTargetStartFadeInDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSkipFadeOutAtBindTargeType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> BindZoneEnvAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Priority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TheaterSelectDataList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSkipAlreadyPlaySameTheater;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseStartFadeInScreenForLeveStream;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartFadeInDuration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartFadeInTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bFirstTimeIntro;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUseEndFadeInScreenForLeveStream;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingApplyType1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingLocation1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingRotation1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingScale1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingApplyType2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingLocation2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingRotation2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MeshClipingScale2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bCancelWhenPlayerWarp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bBlockInputByBindSequence;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
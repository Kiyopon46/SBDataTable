#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBZoneTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBZoneTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString WorldAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString IsolatedAreaAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bOverrideIsolatedAreaWithWorldMap;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString NpcTransitType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitActive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrainningRoom;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StartPointAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnterZoneResetLayerList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LeaveZoneResetLayerList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnterEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LeaveEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ActiveEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DeactiveEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ZoneSpawnEvents;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnterZoneEffectTargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnterZoneEffectAtLeaveState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EnterZoneEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TransitAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> TransitZone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> LoadLevels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> UnloadLevels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRestoreLevelWhenLeave;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlayRule;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpiritRoomEscapeCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpiritRoomEscapeConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSpiritRoom_ChoiceOpenPopup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString LevelGraphicsOptionsAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverrideEnterZoneFadeInDelayTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AdditiveDesignLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
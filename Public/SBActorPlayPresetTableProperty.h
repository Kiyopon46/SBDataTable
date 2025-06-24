#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBActorPlayPresetTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBActorPlayPresetTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 WeaponLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BodyLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 BetaLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TumblerLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExoSpineLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 GearLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PlayerDifficultyStatGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AcquisitionSkillList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> PreCompleteAchievementAliasList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> MaintainCompleteAchievementList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemAmountList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ItemLevelList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Gear1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Gear2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Gear3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Gear4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_NanoSuit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Protector1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Protector2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Hair1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Accessory1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Accessory2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EquipItem_Drone;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Hair1_ColorIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
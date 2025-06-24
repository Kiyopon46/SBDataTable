#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBAcquisitionSkillTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBAcquisitionSkillTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UsableSlot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConsumeItemAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConsumeItemAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ConsumeSP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bExceptReset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString RequiredCompleteAchievement;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> RequiredAcquisitionSkillAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool OrCheckRequiredAcquisition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString VisibleCondition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool AcquisitionOnCreated;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PassiveSkillFunctionAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillIconName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillPreviewPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillEnergyVisibleType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillImportanceType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillTreeAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillSlotAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AchievementTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Command;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillPriorityAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SkillCommandAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TrainingRoom;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
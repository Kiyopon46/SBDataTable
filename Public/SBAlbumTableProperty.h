#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBAlbumTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBAlbumTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EntityAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AlbumType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool PopupWhenUnlock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool PauseWhenPopup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Asset2DIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Asset2DImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AchievementUnlocked;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AchievementUsed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AchievementPopup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ConditionGroupDisplay;

};
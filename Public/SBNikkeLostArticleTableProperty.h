#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBNikkeLostArticleTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBNikkeLostArticleTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ClearShowTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ClearSequenceTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemSkeletalMeshPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemAnimAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemMeshTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ClearNikkeStageAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ClearSequencePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> ClearSequenceUITime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ClearRewardGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Category;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ImageAssetPath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MusicQNRTAssetPath;

};
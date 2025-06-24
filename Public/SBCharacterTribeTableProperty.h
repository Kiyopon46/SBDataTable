#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBCharacterTribeTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBCharacterTribeTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetTribe10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetRelation10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
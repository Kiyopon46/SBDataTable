#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBTransformCharacterTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBTransformCharacterTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Score;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight6;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight7;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight9;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterAlias10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
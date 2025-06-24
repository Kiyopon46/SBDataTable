#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBAreaControlVolumeTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBAreaControlVolumeTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InitActivate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AdmissionPossibleTribeArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AdmissionPossibleCharacterTagArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bRemoveNotKeepSBCharacter;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SaveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
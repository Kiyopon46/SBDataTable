#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBNewGamePlusAlreadySetupTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBNewGamePlusAlreadySetupTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ObjectType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DataAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StateName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Enable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
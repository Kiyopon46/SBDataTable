#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBLevelTargetFilterTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBLevelTargetFilterTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EventSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TargetAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpawnPointName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TargetPriority;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
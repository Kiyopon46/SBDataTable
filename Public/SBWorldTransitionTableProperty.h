#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBWorldTransitionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBWorldTransitionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TransitionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnableConditionGroup;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TriggerAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ZoneEventAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnvSpawnAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> EventSpawnAliasArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FromWorldAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FromIsolatedAreaAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToWorldAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToIsolatedAreaAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ToDescStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PortalTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool EnableWorldMapPortal;

};
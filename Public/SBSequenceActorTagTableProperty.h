#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBSequenceActorTagTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBSequenceActorTagTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TextActorKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ActorTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
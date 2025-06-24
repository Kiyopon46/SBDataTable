#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBArtBookTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBArtBookTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TitleStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ArtistStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ImagePath;

};
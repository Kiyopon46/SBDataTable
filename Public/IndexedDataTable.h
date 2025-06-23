#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "IndexedDataTable.generated.h"

/**
 * DataTable with indexable column names for optimized lookups.
 */
UCLASS(BlueprintType)
class SB_API UIndexedDataTable : public UDataTable
{
    GENERATED_BODY()

public:
    // Column names to be treated as index keys
    UPROPERTY(EditAnywhere, Category = "Indexing")
        TArray<FName> IndexPropertySet;
};

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBPhotoModeOptionTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBPhotoModeOptionTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OptionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CameraType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UISlotType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString PhotoModeUITab;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bLocked;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIOperateVariableName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ChangeNoticeStringKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float InitialValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DefaultValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MinValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 FloatValueDecimalRoundPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UIMinValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UIMaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UISliderSlotIntervalValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UISliderSlotClickIntervalValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UIErrorTolerance;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OptionToUICurvePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString UIToOptionCurvePath;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> DependencyList;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bOverrideValueOnLocked;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float OverriddenValueOnLocked;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bFreezeCameraOnFocus;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bControlActiveLight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bSetDefaultToFinalPostProcessing;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableValueSnapToNearestUI;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MaterialMaskValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> FloatArrayValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> OptionStringArray;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FString> AliasArrayValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EditorOnlyStepValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SBUITextActionFormatTableProperty.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct SB_API FSBUITextActionFormatTableProperty : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Group;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GameOptionType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GameOptionRedirectValue1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString GameOptionRedirectValue2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StreamInputRedirectValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Platform;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FallBackGroupAlias;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringTableNamespace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringTableKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StringFormat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAction1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAction2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAction3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAction4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Action5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAction5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputDefine1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortInputDefine1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputDefine2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortInputDefine2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputDefine3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortInputDefine3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputDefine4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortInputDefine4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString InputDefine5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortInputDefine5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Axis1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScale1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAxis1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Axis2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScale2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAxis2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Axis3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScale3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAxis3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Axis4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScale4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAxis4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Axis5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString AxisScale5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortAxis5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SwipeOption;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 SortSwipeOption;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString FileSuffix;

};
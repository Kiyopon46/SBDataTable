#include "Importer/FSBPhotoModeOptionTableImporter.h"
#include "SBPhotoModeOptionTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBPhotoModeOptionTableImporter"

FString FSBPhotoModeOptionTableImporter::GetDataTableName() const
{
    return "PhotoModeOptionTable";
}

TFunction<void()> FSBPhotoModeOptionTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBPhotoModeOptionTableImporter::GetRowStruct() const
{
    return FSBPhotoModeOptionTableProperty::StaticStruct();
}

void FSBPhotoModeOptionTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
{
    // Get "Rows" Object
    const TSharedPtr<FJsonObject>* RowsObjectPtr = nullptr;
    if (!DataTableObject->TryGetObjectField(TEXT("Rows"), RowsObjectPtr) || !RowsObjectPtr) {
        UE_LOG(LogTemp, Error, TEXT("Rows field missing or invalid."));
        return;
    }

    const TSharedPtr<FJsonObject>& RowsObject = *RowsObjectPtr;
    for (const auto& RowPair : RowsObject->Values) {
        FString RowName = RowPair.Key;

        const TSharedPtr<FJsonObject>* RowDataObjectPtr;
        if (!RowPair.Value->TryGetObject(RowDataObjectPtr) || !RowDataObjectPtr) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid row object for RowName: %s"), *RowName);
            continue;
        }

        const TSharedPtr<FJsonObject>& RowDataObject = *RowDataObjectPtr;

        FSBPhotoModeOptionTableProperty NewRow;
        TryApplyIntField(RowDataObject, TEXT("ID"), RowName, [&](int32 Val) { NewRow.ID = Val; });
        TryApplyStringField(RowDataObject, TEXT("OptionType"), RowName, [&](const FString& Val) { NewRow.OptionType = Val; });
        TryApplyStringField(RowDataObject, TEXT("CameraType"), RowName, [&](const FString& Val) { NewRow.CameraType = Val; });
        TryApplyStringField(RowDataObject, TEXT("UISlotType"), RowName, [&](const FString& Val) { NewRow.UISlotType = Val; });
        TryApplyStringField(RowDataObject, TEXT("PhotoModeUITab"), RowName, [&](const FString& Val) { NewRow.PhotoModeUITab = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bLocked"), RowName, [&](bool Val) { NewRow.bLocked = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIOperateVariableName"), RowName, [&](const FString& Val) { NewRow.UIOperateVariableName = Val; });
        TryApplyStringField(RowDataObject, TEXT("ChangeNoticeStringKey"), RowName, [&](const FString& Val) { NewRow.ChangeNoticeStringKey = Val; });
        TryApplyFloatField(RowDataObject, TEXT("InitialValue"), RowName, [&](float Val) { NewRow.InitialValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DefaultValue"), RowName, [&](float Val) { NewRow.DefaultValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MinValue"), RowName, [&](float Val) { NewRow.MinValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("MaxValue"), RowName, [&](float Val) { NewRow.MaxValue = Val; });
        TryApplyIntField(RowDataObject, TEXT("FloatValueDecimalRoundPoint"), RowName, [&](int32 Val) { NewRow.FloatValueDecimalRoundPoint = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UIMinValue"), RowName, [&](float Val) { NewRow.UIMinValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UIMaxValue"), RowName, [&](float Val) { NewRow.UIMaxValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UISliderSlotIntervalValue"), RowName, [&](float Val) { NewRow.UISliderSlotIntervalValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UISliderSlotClickIntervalValue"), RowName, [&](float Val) { NewRow.UISliderSlotClickIntervalValue = Val; });
        TryApplyFloatField(RowDataObject, TEXT("UIErrorTolerance"), RowName, [&](float Val) { NewRow.UIErrorTolerance = Val; });
        TryApplyStringField(RowDataObject, TEXT("OptionToUICurvePath"), RowName, [&](const FString& Val) { NewRow.OptionToUICurvePath = Val; });
        TryApplyStringField(RowDataObject, TEXT("UIToOptionCurvePath"), RowName, [&](const FString& Val) { NewRow.UIToOptionCurvePath = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("DependencyList"), RowName, [&](const TArray<FString>& Val) { NewRow.DependencyList = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bOverrideValueOnLocked"), RowName, [&](bool Val) { NewRow.bOverrideValueOnLocked = Val; });
        TryApplyFloatField(RowDataObject, TEXT("OverriddenValueOnLocked"), RowName, [&](float Val) { NewRow.OverriddenValueOnLocked = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bFreezeCameraOnFocus"), RowName, [&](bool Val) { NewRow.bFreezeCameraOnFocus = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bControlActiveLight"), RowName, [&](bool Val) { NewRow.bControlActiveLight = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bSetDefaultToFinalPostProcessing"), RowName, [&](bool Val) { NewRow.bSetDefaultToFinalPostProcessing = Val; });
        TryApplyBoolField(RowDataObject, TEXT("bEnableValueSnapToNearestUI"), RowName, [&](bool Val) { NewRow.bEnableValueSnapToNearestUI = Val; });
        TryApplyStringField(RowDataObject, TEXT("MaterialMaskValue1"), RowName, [&](const FString& Val) { NewRow.MaterialMaskValue1 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("FloatArrayValue1"), RowName, [&](const TArray<FString>& Val) { NewRow.FloatArrayValue1 = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("OptionStringArray"), RowName, [&](const TArray<FString>& Val) { NewRow.OptionStringArray = Val; });
        TryApplyStringArrayField(RowDataObject, TEXT("AliasArrayValue1"), RowName, [&](const TArray<FString>& Val) { NewRow.AliasArrayValue1 = Val; });
        TryApplyFloatField(RowDataObject, TEXT("EditorOnlyStepValue"), RowName, [&](float Val) { NewRow.EditorOnlyStepValue = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

#include "Importer/FSBCharacterDeadTableImporter.h"
#include "SBCharacterDeadTableProperty.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "FSBCharacterDeadTableImporter"

FString FSBCharacterDeadTableImporter::GetDataTableName() const
{
    return "CharacterDeadTable";
}

TFunction<void()> FSBCharacterDeadTableImporter::GetMenuCallback()
{
    return [this]()
    {
        this->Execute();
    };
}

UScriptStruct* FSBCharacterDeadTableImporter::GetRowStruct() const
{
    return FSBCharacterDeadTableProperty::StaticStruct();
}

void FSBCharacterDeadTableImporter::PopulateDataTable(UDataTable* TargetTable, const TSharedPtr<FJsonObject>& DataTableObject)
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

        FSBCharacterDeadTableProperty NewRow;
        TryApplyStringArrayField(RowDataObject, TEXT("DefaultDeadShowArray"), RowName, [&](const TArray<FString>& Val) { NewRow.DefaultDeadShowArray = Val; });
        TryApplyIntField(RowDataObject, TEXT("DefaultDeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.DefaultDeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DefaultDeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.DefaultDeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DefaultDeadUIDelayTime"), RowName, [&](float Val) { NewRow.DefaultDeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("MoveAliasWhenDead"), RowName, [&](const FString& Val) { NewRow.MoveAliasWhenDead = Val; });
        TryApplyStringField(RowDataObject, TEXT("StandDeadShow"), RowName, [&](const FString& Val) { NewRow.StandDeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("StandDeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.StandDeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("StandDeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.StandDeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("StandDeadUIDelayTime"), RowName, [&](float Val) { NewRow.StandDeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Step0DeadShow"), RowName, [&](const FString& Val) { NewRow.Step0DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Step0DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Step0DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Step0DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Step0DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Step0DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Step0DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Step1DeadShow"), RowName, [&](const FString& Val) { NewRow.Step1DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Step1DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Step1DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Step1DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Step1DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Step1DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Step1DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Step2DeadShow"), RowName, [&](const FString& Val) { NewRow.Step2DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Step2DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Step2DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Step2DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Step2DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Step2DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Step2DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Step3DeadShow"), RowName, [&](const FString& Val) { NewRow.Step3DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Step3DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Step3DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Step3DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Step3DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Step3DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Step3DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Explosion1DeadShow"), RowName, [&](const FString& Val) { NewRow.Explosion1DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Explosion1DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Explosion1DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Explosion1DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Explosion1DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Explosion1DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Explosion1DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Explosion2DeadShow"), RowName, [&](const FString& Val) { NewRow.Explosion2DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Explosion2DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Explosion2DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Explosion2DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Explosion2DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Explosion2DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Explosion2DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom1DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom1DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom1DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom1DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom1DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom1DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom1DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom1DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom2DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom2DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom2DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom2DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom2DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom2DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom2DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom2DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom3DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom3DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom3DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom3DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom3DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom3DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom3DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom3DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom4DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom4DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom4DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom4DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom4DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom4DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom4DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom4DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom5DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom5DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom5DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom5DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom5DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom5DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom5DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom5DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom6DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom6DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom6DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom6DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom6DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom6DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom6DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom6DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom7DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom7DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom7DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom7DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom7DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom7DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom7DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom7DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom8DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom8DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom8DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom8DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom8DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom8DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom8DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom8DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom9DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom9DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom9DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom9DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom9DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom9DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom9DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom9DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("Custom10DeadShow"), RowName, [&](const FString& Val) { NewRow.Custom10DeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("Custom10DeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.Custom10DeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("Custom10DeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.Custom10DeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("Custom10DeadUIDelayTime"), RowName, [&](float Val) { NewRow.Custom10DeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("DownDeadShow"), RowName, [&](const FString& Val) { NewRow.DownDeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("DownDeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.DownDeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("DownDeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.DownDeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("DownDeadUIDelayTime"), RowName, [&](float Val) { NewRow.DownDeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("AirborneDeadShow"), RowName, [&](const FString& Val) { NewRow.AirborneDeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("AirborneDeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.AirborneDeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("AirborneDeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.AirborneDeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("AirborneDeadUIDelayTime"), RowName, [&](float Val) { NewRow.AirborneDeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("SwimmingDeadShow"), RowName, [&](const FString& Val) { NewRow.SwimmingDeadShow = Val; });
        TryApplyIntField(RowDataObject, TEXT("SwimmingDeadRewardDelayTime"), RowName, [&](int32 Val) { NewRow.SwimmingDeadRewardDelayTime = Val; });
        TryApplyBoolField(RowDataObject, TEXT("SwimmingDeadSkipDespawnShow"), RowName, [&](bool Val) { NewRow.SwimmingDeadSkipDespawnShow = Val; });
        TryApplyFloatField(RowDataObject, TEXT("SwimmingDeadUIDelayTime"), RowName, [&](float Val) { NewRow.SwimmingDeadUIDelayTime = Val; });
        TryApplyStringField(RowDataObject, TEXT("AdditiveDeadShow"), RowName, [&](const FString& Val) { NewRow.AdditiveDeadShow = Val; });
        TryApplyStringField(RowDataObject, TEXT("FileSuffix"), RowName, [&](const FString& Val) { NewRow.FileSuffix = Val; });

        // Add to DataTable (assuming you have created a UDataTable* TargetTable beforehand)
        TargetTable->AddRow(FName(*RowName), NewRow);

        UE_LOG(LogTemp, Log, TEXT("Added row: %s"), *RowName);
    }
}

#undef LOCTEXT_NAMESPACE

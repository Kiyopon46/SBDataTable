#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Engine/DataTable.h"

class FSBDataTableImporter
{
public:
    virtual ~FSBDataTableImporter() {}

    // JSONファイルを読み込み、"Rows" 部分を返す
    virtual TSharedPtr<FJsonObject> LoadJsonRows(const FString& FilePath) = 0;

    // DataTable に行データを流し込む
    virtual void PopulateDataTable(UDataTable* Table, const TSharedPtr<FJsonObject>& RowsObject) = 0;

    // 出力先 DataTable のパッケージパス（例："/Game/Local/Data/CharacterTable"）
    virtual FString GetPackagePath() const = 0;

    // 対応する構造体
    virtual UScriptStruct* GetRowStruct() const = 0;

protected:

    void TryApplyStringField(
        const TSharedPtr<FJsonObject>& JsonObject,
        const FString& Key,
        const FString& RowName,
        TFunction<void(const FString&)> Setter)
    {
        FString Value;
        if (JsonObject->TryGetStringField(Key, Value))
        {
            Setter(Value);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid Data in Row '%s': Missing key '%s'"), *RowName, *Key);
        }
    }

    void TryApplyIntField(
        const TSharedPtr<FJsonObject>& JsonObject,
        const FString& Key,
        const FString& RowName,
        TFunction<void(int32)> Setter)
    {
        int32 Value;
        if (JsonObject->TryGetNumberField(Key, Value))
        {
            Setter(Value);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid Data in Row '%s': Missing or invalid int key '%s'"), *RowName, *Key);
        }
    }

    void TryApplyFloatField(
        const TSharedPtr<FJsonObject>& JsonObject,
        const FString& Key,
        const FString& RowName,
        TFunction<void(float)> Setter)
    {
        double Temp;
        if (JsonObject->TryGetNumberField(Key, Temp))
        {
            Setter(static_cast<float>(Temp));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid Data in Row '%s': Missing or invalid float key '%s'"), *RowName, *Key);
        }
    }

    void TryApplyStringArrayField(
        const TSharedPtr<FJsonObject>& JsonObject,
        const FString& Key,
        const FString& RowName,
        TFunction<void(const TArray<FString>&)> Setter)
    {
        const TArray<TSharedPtr<FJsonValue>>* JsonArray;
        if (JsonObject->TryGetArrayField(Key, JsonArray))
        {
            TArray<FString> Result;
            for (const auto& Val : *JsonArray)
            {
                Result.Add(Val->AsString());
            }
            Setter(Result);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid Data in Row '%s': Missing or invalid array key '%s'"), *RowName, *Key);
        }
    }

    void TryApplyBoolField(
        const TSharedPtr<FJsonObject>& JsonObject,
        const FString& Key,
        const FString& RowName,
        TFunction<void(bool)> Setter)
    {
        bool bVal;
        if (JsonObject->TryGetBoolField(Key, bVal))
        {
            Setter(bVal);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Invalid Data in Row '%s': Missing or invalid bool key '%s'"), *RowName, *Key);
        }
    }

};
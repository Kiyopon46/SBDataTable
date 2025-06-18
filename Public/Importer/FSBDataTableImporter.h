#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Engine/DataTable.h"
#include "FSBMenuEntry.h"

class FSBDataTableImporter
{
public:
    virtual ~FSBDataTableImporter() {}

    virtual FSBMenuEntry GetMenuEntry() = 0;

    /**
     * Get the package path of the output DataTable (e.g. "/Game/Local/Data/CharacterTable")
     */
    virtual FString GetPackagePath() const = 0;

    /**
     * Returns the UScriptStruct object representing the type information of the DataTable row. 
     */
    virtual UScriptStruct* GetRowStruct() const = 0;

    /**
     * Populating a DataTable with Row Data
     */
    virtual void PopulateDataTable(UDataTable* Table, const TSharedPtr<FJsonObject>& RowsObject) = 0;

protected:

    /**
     * Main processing called for each handlers.
     * @param Importer Importer for each DataTable
     */
    void Execute();

    /** Check if the file exists */
    UDataTable* GetExistingTable(const FString& PackagePath);

    /** Open a dialog to get the JSON file path. */
    FString GetJsonFilePath();

    /**
     * Read the JSON file and get the "Rows" object from it.
     * The following file formats are supported:
     * <code>
     * [
     *   {
     *     "Rows": {
     *       "RowName1": {
     *         // DataTable structure.
     *       },
     *       ...
     *     }
     *   }
     * ]
     * </code>
     */
    TSharedPtr<FJsonObject> LoadJsonRows(const FString& FilePath);

    UDataTable* CreateDataTable();

    void SaveDataTableAsset(
        UDataTable* DataTable, const FString& PackagePath);

    /**
     * Get the string value by specifying the key and set it in the DataTable.
     */
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

    /**
     * Get the integer value by specifying the key and set it in the DataTable.
     */
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

    /**
     * Get the float value by specifying the key and set it in the DataTable.
     */
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

    /**
     * Get the string array value by specifying the key and set it in the DataTable.
     */
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

    /**
     * Get the boolean value by specifying the key and set it in the DataTable.
     */
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
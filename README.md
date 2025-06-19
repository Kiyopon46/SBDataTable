[日本語](docs/ja/README-ja.md) | English

# SBDataTable

## Introduction

This project is a tool designed to overwrite DataTable assets used in the PC version of **Stellar Blade** for various in-game configurations. You can extract these assets as `.json` files using a tool called **FModel**, edit them as needed, and then re-import them via a plugin in the **Unreal Engine 4.26 Editor** (hereafter "UE4 Editor") to generate updated DataTable assets.

This project consists of two GitHub repositories:

1. [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) – A plugin to be installed into the UE4 Editor.
2. [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) – Contains definitions and import logic for each DataTable.

Updates such as support for additional DataTables are primarily made to the [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) repository.

## Requirements

- The retail version of **Stellar Blade (PC)** must be installed.
- You must be able to create a project in **Unreal Engine 4.26 Editor**.
- **Visual Studio 2019** or later must be installed and capable of compiling C++ code.

## Installation

Follow these steps to set up the environment:

1. Create a new UE4.26 project. The project name can be anything.
2. Create a `Source` folder at the root of your project and either extract the latest release ZIP of this repository or clone it directly.
3. Similarly, create a `Plugins` folder at the root and extract or clone the sister project [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) into it.
4. At this point, your folder structure should look like this:
    - `/YourProjectName/Plugins/SBEditorTools/`
    - `/YourProjectName/Source/SBDataTable/`
5. Restart the UE4 Editor if it is currently running.
6. In the restarted UE4 Editor, go to **Edit → Plugins**, search for "SB", and enable the **SBEditorTools** plugin.
7. You’ll be prompted to restart the UE4 Editor again—please do so.
8. Upon restart, you will be asked to build SBEditorTools—proceed with the build.
9. Once the build is complete and the UE4 Editor launches, setup is complete.
10. You should now see a **"SB Tools"** menu added to the UE4 Editor’s main menu bar.

## How to Use

1. From the main menu bar, select **SB Tools → DataTable → (Target DataTable Name)**.  
   If the selected DataTable hasn’t been created yet in the UE4 Editor, a file dialog will immediately appear for selecting a `.json` file.  
   If it already exists, a confirmation dialog will prompt you for overwriting. If you select "Yes", the corresponding DataTable asset will be deleted from the UE4 Editor before the file dialog is shown—**please proceed with caution**.
   
2. After selecting the appropriate `.json` file, the DataTable will be created in the appropriate folder (typically under `Content/Local/Data`).  
   Make sure the `.json` file matches the structure of the DataTable you are trying to import.  
   For reference, sample `.json` files extracted from **Stellar Blade PC v1.1.2** are available in the `Resources/json/` folder.

3. Once created, you can package the DataTable into a chunk and pack it as usual.

## Attention!!
You may encounter packing issues when compiling and running.  If so, you'll need to disable Smart App Control.  Only use this if you've already disabled it or have the ability to.

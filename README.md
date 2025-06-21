[日本語](docs/ja/README-ja.md) | English

# SBDataTable

## Introduction

This project is a tool designed to overwrite DataTable assets used in the PC version of **Stellar Blade** for various in-game configurations. You can extract these assets as `.json` files using a tool called **FModel**, edit them as needed, and then re-import them via a plugin in the **Unreal Engine 4.26 Editor** (hereafter "UE4 Editor") to generate updated DataTable assets.

This project consists of two GitHub repositories:

1. [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) – Contains definitions and import logic for each DataTable.
2. [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) – A plugin to be installed into the UE4 Editor.

Updates such as support for additional DataTables are primarily made to the [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) repository.

## Requirements

- The retail version of **Stellar Blade (PC)** must be installed.
- You must be able to create a project in **Unreal Engine 4.26 Editor**.
- **Visual Studio 2019** or later must be installed and capable of compiling C++ code.

## Installation

For detailed **usage instructions**, please refer to the [README.md of SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/blob/main/README.md).

---

## 🛠 How to Add a New DataTable

A detailed guide will be provided at a later time.  
Until then, please refer to [this commit where `BossChallengeTable` was added](https://github.com/Kiyopon46/SBDataTable/commit/baad337de9b6119d18309958a0242ec9f24725b5) for an example.

---

## ⚠️ Important Notes

There may be security issues during compilation or packaging.

### Smart App Control Blocking During Packaging

In Windows 11, the following issues may occur when packaging a C++ project:

- Temporary DLL files generated under `AppData/Local/Temp/UAT` fail to load
- Packaging process is interrupted

This issue arises due to **Smart App Control (SAC)** or **SmartScreen** blocking unsigned temporary files.  
The `Output Log` may contain errors like the following:

```
ERROR: System.IO.FileLoadException: ファイルまたはアセンブリ 'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll'、またはその依存関係の 1 つが読み込めませんでした。アプリケーション制御ポリシーによってこのファイルがブロックされました。 (HRESULT からの例外:0x800711C7)
       ファイル名 'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll' です。'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll'
       ......

PackagingResults: Error: System.IO.FileLoadException: ファイルまたはアセンブリ 'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll'、またはその依存関係の 1 つが読み込めませんでした。アプリケーション制御ポリシーによってこのファイルがブロックされました。 (HRESULT からの例外:0x800711C7)
```

### 🔧 Solution

- Disable Smart App Control

If this error occurs, you may need to disable Smart App Control in Windows 11.  
Note that once disabled, re-enabling it requires OS reinstallation. Use this function only if you have already disabled SAC or do not mind it remaining disabled.


## ⚠️ Usage Restrictions

This repository is not distributed under any formal open-source license.  
It is intended primarily for sharing technical knowledge within the [**AyakaMods** community](https://discord.gg/stellarblademodding), not for wide public distribution of the source code.

If you use the tools in this repository to create MODs that **significantly degrade the gameplay experience** of **Stellar Blade** (e.g., drastically lowering a boss's Max HP),  
such use is tolerated **only for personal or private use among trusted individuals**.  
**Public distribution** of such MODs, including on social media or mod-sharing platforms, is strictly prohibited.

On the other hand, MODs that **enhance the gameplay experience** are welcome to be shared publicly.

If you are unsure whether your MOD would significantly degrade the experience, **please refrain from using this repository**.

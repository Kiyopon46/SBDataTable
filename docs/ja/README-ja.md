日本語 | [English](../../README.md)

# SBDataTable

## はじめに

**SBDataTable** は、Stellar Blade (PC版) における DataTable アセットを上書きするためのツールである `SBEditorTools` で使用されるデータ定義です。  
`SBEditorTools` はゲーム本編から FModel というツールを使って .json 形式で DataTable を抽出し、それを任意に編集した後、Unreal Engine 4.26 Editor (以下、UE4 Editor) 上で再インポートすることができます。

本機能は、次の2つの GitHub リポジトリで構成されています：

1. [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) - 各種 DataTable の定義と、実際のインポート処理

2. [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) - UE4 Editor に導入するプラグイン

DataTable の追加など、プロジェクトのアップデートは主に本リポジトリである [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) 側で行われます。

---

## 前提条件

以下の環境が必要です：

- Stellar Blade (PC版 製品版) がインストールされている
- Unreal Engine 4.26 Editor で C++ プロジェクトが作成可能
- Visual Studio 2019 以上がインストールされており、C++ のビルドが可能

---

UE4 Editor に導入する `SBEditorTools` プラグインの具体的な **導入手順** 以降は [SBEditorTools の README-ja.md](https://github.com/Kiyopon46/SBEditorTools/blob/main/docs/ja/README-ja.md) をご覧ください。

---

## 🛠 新しい DataTable の追加方法

後日あらためて詳述したいと考えていますが、それまでは  
[BossChallengeTable を追加した際のコミット](https://github.com/Kiyopon46/SBDataTable/commit/baad337de9b6119d18309958a0242ec9f24725b5) を参考にしてください。


---

## ⚠️ 要注意

コンパイルおよびパッキング実行時にセキュリティの問題が発生する可能性があります。

### パッケージング時の Smart App Control 等によるブロックについて

Windows 11 環境で C++ プロジェクトをパッケージングする際、以下のような現象が発生することがあります：

- `AppData/Local/Temp/UAT` 以下に一時的に生成された DLL ファイルの読み込みに失敗する
- 結果としてパッケージングが中断される

この現象は、**Smart App Control（SAC）または SmartScreen** によって、署名されていない一時ファイルの読み込みがブロックされるために発生します。  
この場合、 `Output Log` に次のようなログとスタックとレースが出力されます。

```
ERROR: System.IO.FileLoadException: ファイルまたはアセンブリ 'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll'、またはその依存関係の 1 つが読み込めませんでした。アプリケーション制御ポリシーによってこのファイルがブロックされました。 (HRESULT からの例外:0x800711C7)
       ファイル名 'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll' です。'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll'
       ......

PackagingResults: Error: System.IO.FileLoadException: ファイルまたはアセンブリ 'file:///C:\Users\PC_User\AppData\Local\Temp\UAT\C+Program+Files+Epic+Games+UE_4.26\Rules\UATRules1622703478.dll'、またはその依存関係の 1 つが読み込めませんでした。アプリケーション制御ポリシーによってこのファイルがブロックされました。 (HRESULT からの例外:0x800711C7)
```

### 🔧 対処法

- Smart App Control を無効化する

このエラーが発生した場合、 Windows11 のスマートアプリコントロールを無効にする必要がある場合があります。  
一度無効にすると再度有効にするには OS の再インストールが必要になるため、既に無効にしている場合、または無効のままにしていても構わない場合にのみ、本機能をご利用ください。

## ⚠️ 制限事項

本リポジトリには明示的なライセンスは付与されていません。  
本リポジトリはソースコードの広範な配布を目的としたものではなく、[**AyakaMods** コミュニティ](https://discord.gg/stellarblademodding) 内での情報共有を主目的としています。

本リポジトリに含まれる機能を用いて **Stellar Blade** のゲーム体験を著しく損なう MOD を作成した場合 (例：ボスの MaxHP を極端に下げるなど) 、  
その使用は「個人利用」や「信頼できる仲間内でのクローズドな共有」に限り許容されます。  
SNS や MOD 配布サイトなどでの**一般公開は固く禁止**します。

一方で、**ゲーム体験をより豊かにするような MOD**については、一般公開も歓迎されます。

なお、「ゲーム体験を著しく損なう」とは何か判断できない方の使用はご遠慮ください。

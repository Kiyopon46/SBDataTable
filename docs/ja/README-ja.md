日本語 | [English](../../README.md)

# SBDataTable

## はじめに

**SBDataTable** は、Stellar Blade（PC版）における DataTable アセットを上書きするためのツールです。  
ゲーム本編から FModel というツールを使って .json 形式で DataTable を抽出し、それを任意に編集した後、Unreal Engine 4.26 Editor（以下、UE4 Editor）上で再インポートすることができます。

本プロジェクトは、次の2つの GitHub リポジトリで構成されています：

1. [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) - UE4 Editor に導入するプラグイン
2. [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) - 各種 DataTable の定義と、実際のインポート処理

DataTable の追加など、プロジェクトのアップデートは主に [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) 側で行われます。

---

## 前提条件

以下の環境が必要です：

- Stellar Blade（PC版 製品版）がインストールされている
- Unreal Engine 4.26 Editor で C++ プロジェクトが作成可能
- Visual Studio 2019 以上がインストールされており、C++ のビルドが可能

---

## 導入手順

1. Unreal Engine 4.26 で任意の名前でプロジェクトを作成します。
2. プロジェクト直下に `Source` フォルダを作成し、本リポジトリの ZIP を展開するか、任意のコミットをクローンします。
3. 同様に `Plugins` フォルダを作成し、[SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) の ZIP を展開するか、任意のコミットをクローンします。
4. フォルダ構成は以下のようになります：
```
/YourProjectName/
├── Plugins/
│ └── SBEditorTools/
└── Source/
  └── SBDataTable/
```
5. UE4 Editor が起動中であれば一度終了し、再起動してください。
6. UE4 Editor のメニューから「Edit → Plugins」を開き、「SB」と検索し、`SBEditorTools` を有効化します。
7. プラグインの有効化後に再起動を求められるので、再起動します。
8. 再起動時にビルドを求められたら、ビルドを実行します。
9. UE4 Editor 起動後、メニューバーに「SB Tools」が追加されていれば準備完了です。

---

## 使い方

1. メニューバーから「SB Tools → DataTable → （作成したい DataTable 名）」を選択します。
 - UE4 Editor 上に対象の DataTable が存在しない場合：  
   `.json` ファイルを選択するダイアログが表示されます。
 - すでに存在する場合：  
   上書き確認のダイアログが表示され、「Yes」を選択すると DataTable が削除された上でファイル選択に進みます（※削除に注意）。

2. `.json` ファイルを選択すると、内容に基づいて DataTable アセットが作成されます。  
通常は `Content/Local/Data/` 以下に出力されます。  
**DataTable の種類に対応した `.json` ファイルを選んでください。**

参考用に、Stellar Blade PC版 v1.1.2 時点の `.json` ファイルを `Resources/json/` フォルダに同梱しています。

3. あとは通常通り、作成された DataTable を chunk に含めてパックすれば完了です。

---

## 🛠 新しい DataTable の追加方法

後日あらためて詳述したいと考えていますが、それまでは  
[BossChallengeTable を追加した際のコミット](https://github.com/Kiyopon46/SBDataTable/commit/baad337de9b6119d18309958a0242ec9f24725b5) を参考にしてください。


---

## ⚠️ 要注意
コンパイルおよび実行時にパッキングの問題が発生する可能性があります。その場合は、Windows11のスマートアプリコントロールを無効にする必要があります。既に無効にしている場合、または無効にできる場合にのみ、この本機能をご利用ください。

## ⚠️ 制限事項

本リポジトリには明示的なライセンスは付与されていません。  
本リポジトリはソースコードの広範な配布を目的としたものではなく、[**AyakaMods** コミュニティ](https://discord.gg/stellarblademodding) 内での情報共有を主目的としています。

本リポジトリに含まれる機能を用いて **Stellar Blade** のゲーム体験を著しく損なう MOD を作成した場合（例：ボスの MaxHP を極端に下げるなど）、  
その使用は「個人利用」や「信頼できる仲間内でのクローズドな共有」に限り許容されます。  
SNS や MOD 配布サイトなどでの**一般公開は固く禁止**します。

一方で、**ゲーム体験をより豊かにするような MOD**については、一般公開も歓迎されます。

なお、「ゲーム体験を著しく損なう」とは何か判断できない方の使用はご遠慮ください。

日本語 | [English](../../README.md)

# SBDataTable

## はじめに

このプロジェクトは Stellar Blade PC版における、各種設定を行っている DataTable というアセットを上書きすることを目的としたツールです。ゲーム本編から FModel というツールでこれらのアセットを .json ファイルとして抽出し、その .json ファイルを任意に編集した後、それを Unreal Engine 4.26 Editor（以下、UE4 Editor）上でプラグイン経由で読み込むことで DataTable アセットを作成することができます。

このプロジェクトは次の２つの GitHub リポジトリで構成されます。

1. [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) : UE4 Editor に導入するプラグイン
1. [SBDataTable](https://github.com/Kiyopon46/SBDataTable/) : 各データテーブルの定義と実際のインポート処理

対応する DataTable の追加などの当プロジェクトのアップデートは主に [SBDataTable](https://github.com/Kiyopon46/SBDataTable/)  に対して行われます。

## 前提環境

* Stellar Blade PC版（製品版）がインストール済みであること。
* Unreal Engine 4.26 Editor でプロジェクトを作成できること。
* Visual Studio 2019 以上がインストール済みで C++ のビルドができること。

## 導入の流れ

以下に導入の流れを示します。

1. Unreal Engine 4.26 でプロジェクトを作成します。プロジェクト名は任意で問題ありません。
1. プロジェクトフォルダの直下にSourceフォルダを作り、本リポジトリの最新リリースの zip ファイルを展開するか、リポジトリの任意のコミットをクローンします。
1. 同じくプロジェクトフォルダの直下に Plugins フォルダを作り、姉妹プロジェクトである [SBEditorTools](https://github.com/Kiyopon46/SBEditorTools/) リポジトリの最新リリースの zip ファイルを展開するか、リポジトリの任意のコミットをクローンします。
1. ここまででフォルダ構成は次のようになります。
    * /(プロジェクト名)/Plugins/SBEditorTools/
    * /(プロジェクト名)/Source/SBDataTable/
1. UE4 Editor が起動している場合は再起動します。
1. 再起動された UE4 Editor のメニューから「Edit」→「Plugins」と進み、検索窓で「SB」と入力し、「SBEditorTools」が表示されたらそのEnabledのチェックを ON にします。
1. UE4 Editor の再起動を促されるので再起動します。
1. 再起動時に SBEditorTools のビルドを促されるのでビルドします。
1. ビルド後 UE4 Editor が起動するので、これで準備完了です。
1. UE4 Editor のメニューバーに「SB Tools」というメニューが追加されているのを確認します。

## 使い方

1. メニューバーの「SB Tools」→「DataTable」→「(作成したい DataTable 名)」と選択してください。UE4 Editor 上にまだその DataTable を作成していない場合はすぐにファイル選択ダイアログが表示され .json ファイルの読み込みに進みます。既に存在する場合は上書き確認のダイアログが表示されます。このダイアログで Yes を選択するとファイル選択ダイアログが表示されますが、その場で該当する DataTable が UE4 Editor から削除されますのでご注意ください。
1. ファイル選択ダイアログで .json ファイルを選択すると、その内容が設定された DataTable が必要なフォルダに作成されます（主に Content/Local/Data フォルダの下）。作成する DataTable の種類に合った .json ファイルを指定してください。参考までに Stellar Blade PC版 1.1.2 時点の DataTable の .json ファイルが Resources/json フォルダの下にありますのでご活用ください。
1. 後はいつも通り作成された DataTable を chunk に含めてパックするだけです。

## Attention!!
You may encounter packing issues when compiling and running.  If so, you'll need to disable Smart App Control.  Only use this if you've already disabled it or have the ability to.
# %%
import os
import json

# %%
def inspect_datatable_properties(json_folder_path):
    # 指定フォルダ内のすべての .json ファイルを対象とする
    for filename in os.listdir(json_folder_path):
        if not filename.lower().endswith(".json"):
            continue

        json_path = os.path.join(json_folder_path, filename)

        try:
            with open(json_path, "r", encoding="utf-8") as f:
                data = json.load(f)

            # JSONの先頭要素がリスト形式であることを確認
            if isinstance(data, list) and data:
                entry = data[0]
                properties = entry.get("Properties", {})

                # RowStruct 以外のキーを抽出
                extra_keys = [k for k in properties.keys() if k != "RowStruct"]
                if extra_keys:
                    print(f"{filename}: Extra Properties -> {extra_keys}")

        except Exception as e:
            print(f"Failed to parse {filename}: {e}")

# %%
# 例: C:/Apps/FModel/Output/Exports/SB/Content/Local/Data フォルダを解析
inspect_datatable_properties("C:/Apps/FModel/Output/Exports/SB/Content/Local/Data")

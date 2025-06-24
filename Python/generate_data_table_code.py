import os
import sys
import json
from datetime import datetime
from pathlib import Path

# テンプレートファイル名
ROW_TEMPLATE = "RowStructHeaderTemplate.txt"
IMPORTER_H_TEMPLATE = "ImporterHeaderTemplate.txt"
IMPORTER_CPP_TEMPLATE = "ImporterCppTemplate.txt"

# フィールド型推定用ヘルパー
def guess_cpp_type(value):
    if isinstance(value, bool):
        return "bool"
    elif isinstance(value, int):
        return "int32"
    elif isinstance(value, float):
        return "float"
    elif isinstance(value, list):
        return "TArray<FString>"
    else:
        return "FString"

def build_field_declaration(name, cpp_type):
    return f"""    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    {cpp_type} {name};"""

def build_try_apply_statement(name, cpp_type):
    if cpp_type == "int32":
        return f'TryApplyIntField(RowDataObject, TEXT("{name}"), RowName, [&](int32 Val) {{ NewRow.{name} = Val; }});'
    elif cpp_type == "float":
        return f'TryApplyFloatField(RowDataObject, TEXT("{name}"), RowName, [&](float Val) {{ NewRow.{name} = Val; }});'
    elif cpp_type == "FString":
        return f'TryApplyStringField(RowDataObject, TEXT("{name}"), RowName, [&](const FString& Val) {{ NewRow.{name} = Val; }});'
    elif cpp_type == "TArray<FString>":
        return f'TryApplyStringArrayField(RowDataObject, TEXT("{name}"), RowName, [&](const TArray<FString>& Val) {{ NewRow.{name} = Val; }});'
    elif cpp_type == "bool":
        return f'TryApplyBoolField(RowDataObject, TEXT("{name}"), RowName, [&](bool Val) {{ NewRow.{name} = Val; }});'
    else:
        return f'// Unknown type: {name}'

def generate_from_json(json_path, templates, output_dir, output_dir_public, output_dir_private):
    with open(json_path, 'r', encoding='utf-8') as f:
        json_data = json.load(f)

    obj = json_data[0]
    data_table_name = obj.get("Name", "UnknownDataTable")
    row_struct_name = obj.get("Properties", {}).get("RowStruct", {}).get("ObjectName", "UnknownStruct")
    if row_struct_name.startswith("Class'"):
        row_struct_name = row_struct_name.split("'")[1]

    rows = obj.get("Rows", {})
    sample_row = next(iter(rows.values())) if rows else {}
    
    field_defs = []
    try_apply = []

    for field_name, value in sample_row.items():
        cpp_type = guess_cpp_type(value)
        field_defs.append(build_field_declaration(field_name, cpp_type))
        try_apply.append(build_try_apply_statement(field_name, cpp_type))

    field_def_text = "\n\n".join(field_defs)
    try_apply_text = "\n        ".join(try_apply)

    replace_dict = {
        "%%%DATA_TABLE_NAME%%%": data_table_name,
        "%%%ROW_STRUCT_NAME%%%": row_struct_name,
        "%%%FIELD_DEFINITION_AREA%%%": field_def_text,
        "%%%TRY_APPLE_AREA%%%": try_apply_text,
    }

    # テンプレートを置換してファイル生成
    def process_template(template_path, prefix, suffix, dir):
        with open(template_path, 'r', encoding='utf-8') as t:
            content = t.read()
        for key, val in replace_dict.items():
            content = content.replace(key, val)
        out_path = dir / f"{prefix}{data_table_name}{suffix}"
        with open(out_path, 'w', encoding='utf-8') as o:
            o.write(content)

    process_template(templates["row"], "SB", "Property.h", output_dir)
    process_template(templates["importer_h"], "FSB", "Importer.h", output_dir_public)
    process_template(templates["importer_cpp"], "FSB", "Importer.cpp", output_dir_private)

def main():
    args = sys.argv[1:]
    if not args:
        print("Usage: python generate_data_table_code.py <.json files or folders>")
        return

    now = datetime.now().strftime("%Y%m%d%H%M%S")
#    output_dir = Path(f"Output_{now}")
    output_dir = Path(f"Output")
    if not output_dir.exists:
        output_dir.mkdir()
    output_dir = Path(f"Output/{now}")
    output_dir.mkdir()
    output_dir_public = Path(f"Output/{now}/Public")
    output_dir_public.mkdir()
    output_dir_private = Path(f"Output/{now}/Private")
    output_dir_private.mkdir()

    # テンプレートファイルの位置
    templates = {
        "row": Path(ROW_TEMPLATE),
        "importer_h": Path(IMPORTER_H_TEMPLATE),
        "importer_cpp": Path(IMPORTER_CPP_TEMPLATE)
    }

    json_files = []
    for arg in args:
        path = Path(arg)
        if path.is_file() and path.suffix == ".json":
            json_files.append(path)
        elif path.is_dir():
            json_files += list(path.glob("*.json"))

    for json_path in json_files:
        generate_from_json(json_path, templates, output_dir, output_dir_public, output_dir_private)

    print(f"Done. Output directory: {output_dir}")

if __name__ == "__main__":
    main()

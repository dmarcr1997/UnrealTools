import unreal
import json
#instance of unreal
editor_util = unreal.EditorUtilityLibrary()
system_lib = unreal.SystemLibrary()
#get selected assets
selected_assets = editor_util.get_selected_assets()
num_assets = len(selected_assets)
prefixed = 0

#prefix_mapping
prefix_maping = {}

with open("C:\\Users\\dmarc\\dev\\Pyth\\unrealTools\\UnrealTools\\Python\\prefix_mapping.json","r") as json_file:
    prefix_maping = json.loads(json_file.read())

for asset in selected_assets:
    #get class name and text name
    asset_name = system_lib.get_object_name(asset)
    asset_class = asset.get_class()
    class_name = system_lib.get_class_display_name(asset_class)

    #get prefix for each asset
    class_prefix = prefix_maping.get(class_name, None)
    
    if class_prefix is None:
        unreal.log_warning("No mapping for asset {} of type {}\n".format(asset_name, class_name))
        continue
    if not asset_name.startswith(class_prefix):
        #rename asset
        new_name = class_prefix + asset_name
        editor_util.rename_asset(asset, new_name)
        prefixed += 1        
        unreal.log("Prefixed {} of type {} with {}".format(asset_name, class_name, class_prefix))
    else:
        unreal.log("Asset {} of type {} is already prefixed with {}".format(asset_name, class_name, class_prefix))

unreal.log("Prefixed {} of {} assets".format(prefixed, num_assets))


import unreal
 
#instance of editor util library
editor_util = unreal.EditorUtilityLibrary()

#get selected items from user
selected_assets = editor_util.get_selected_assets()
num_assets = len(selected_assets)
num_pow = 0

for asset in selected_assets:
    unreal.log(asset.get_fname())
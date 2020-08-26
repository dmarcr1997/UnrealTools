import unreal
import math

#instance of editor util library
editor_util = unreal.EditorUtilityLibrary()

#get selected items from user
selected_assets = editor_util.get_selected_assets()
num_assets = len(selected_assets)
not_pow = 0

for asset in selected_assets:
    #get asset name and x/y sizes
    asset_name = asset.get_fname()
    x_size = asset.blueprint_get_size_x()
    y_size = asset.blueprint_get_size_y()
    asset_path = asset.get_path_name()
    #check if both are a power of 2
    is_x_valid = math.log(x_size, 2).is_integer()
    is_y_valid = math.log(y_size, 2).is_integer()

    if not is_x_valid or not is_y_valid:
        unreal.log("{} is not a power of two({}, {})".format(asset_name, x_size, y_size))
        unreal.log("It's path is {}".format(asset_path))
        not_pow += 1
unreal.log("{} checked, {} textures found problematic".format(num_assets, not_pow))
# Generate platform-agnostic key definitions from GLFW keys

# This script reads GLFW key definitions from the GLFW header file and generates
# platform-agnostic key definitions for use in the engine.
# It outputs the definitions to `KeyCodeDefines.inl` in the engine's input directory.
# This allows the engine to use a consistent set of key codes across all platforms
# without directly depending on GLFW or platform-specific key codes.
# The generated file can be included in the engine's input handling code.

import re
import os

glfw_header = os.path.normpath(
    os.path.join(os.path.dirname(__file__), 
                "../libs/glfw/include/GLFW/glfw3.h")
)

# Parse GLFW keys from header
with open(glfw_header, "r") as f:
    content = f.read()

keys = re.findall(r'#define\s+(GLFW_KEY_\w+)\s+(\d+)', content)

# Generate platform-agnostic key defs
with open("engine/input/KeyCodeDefines.inl", "w") as f:
    f.write("// Auto-generated from GLFW - DO NOT EDIT\n")
    for key in keys:
        key_name = key[0][9:]
        if key_name.isnumeric():
            key_name = f"Num_{key_name}"  # Handle numeric keys
        # first character should be uppercase, rest lowercase
        key_name = key_name[0].upper() + key_name[1:].lower()
        # ensure no special characters
        key_name = re.sub(r'[^A-Za-z0-9]', '', key_name)
        f.write(f"{key_name} = {key[1]},\n")

#pragma once
#include <cstdint>
#include <variant>

// Auto-converted GLFW keys
enum class KeyboardKey : uint16_t {
    #include "KeyCodeDefines.inl"  // Expands to KeyboardKey_Escape=256, etc.
    _Count
};

enum class MouseButton : uint8_t { Left, Right, Middle, _Count };
enum class GamepadButton : uint8_t { A, B, X, Y, _Count };

using InputCode = std::variant<
    KeyboardKey, 
    MouseButton, 
    GamepadButton
>;
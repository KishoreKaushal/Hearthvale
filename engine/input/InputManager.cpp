#include "InputManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <GLFW/glfw3.h>

// Static helper functions
namespace {
    std::string Trim(const std::string& s) {
        auto start = s.find_first_not_of(" \t");
        auto end = s.find_last_not_of(" \t");
        return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
    }

    std::vector<std::string> Split(const std::string& s, char delim) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delim)) {
            token = Trim(token);
            if (!token.empty()) tokens.push_back(token);
        }
        return tokens;
    }

    InputCode ParseKey(const std::string& keyStr) {
        // Keyboard keys
        if (keyStr == "Escape") return KeyboardKey::Escape;
        if (keyStr == "Space") return KeyboardKey::Space;
        if (keyStr == "W") return KeyboardKey::W;
        if (keyStr == "A") return KeyboardKey::A;
        if (keyStr == "S") return KeyboardKey::S;
        if (keyStr == "D") return KeyboardKey::D;

        // Mouse buttons
        if (keyStr == "MouseLeft") return MouseButton::Left;
        if (keyStr == "MouseRight") return MouseButton::Right;

        throw std::runtime_error("Unknown key: " + keyStr);
    }
}


InputManager::InputManager(GLFWwindow* glfWin)
    : window(glfWin)
{
}

void InputManager::BindAction(const std::string& action, InputCode code) {
    m_actions[action].push_back(code);
}

bool InputManager::IsActionPressed(const std::string& action) const {
    // check if action exists
    auto it = m_actions.find(action);
    if (it == m_actions.end())
    {
        // std::cout << "Action " << action << " not found!" << std::endl;
        return false;
    }

    if (!window)
    {
        std::cout << "Window " << window << " not initialized!" << std::endl;
        return false;
    }

    for (const auto& code : m_actions.at(action)) {
        if (std::holds_alternative<KeyboardKey>(code)) {
            auto key = std::get<KeyboardKey>(code);
            return glfwGetKey(window, static_cast<int>(key)) == GLFW_PRESS;
        }
        else if (std::holds_alternative<MouseButton>(code)) {
            auto key = std::get<MouseButton>(code);
            return glfwGetMouseButton(window, static_cast<int>(key)) == GLFW_PRESS;
        }
        /// TODO: write code for gamepad handling
    }
    return false;
}

void InputManager::LoadConfig(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open input config: " + path);
    }

    std::string line;
    while (std::getline(file, line)) {
        // Skip comments/empty lines
        line = line.substr(0, line.find('#')); // Remove comments
        if (line.empty()) continue;

        size_t eqPos = line.find('=');
        if (eqPos != std::string::npos) {
            std::string action = Trim(line.substr(0, eqPos));
            std::string keysStr = Trim(line.substr(eqPos + 1));

            if (!action.empty() && !keysStr.empty()) {
                for (const auto& key : Split(keysStr, ',')) {
                    try {
                        BindAction(action, ParseKey(Trim(key)));
                    } catch (const std::exception& e) {
                        std::cerr << "Invalid key binding: " << key 
                                  << " for action " << action << "\n";
                    }
                }
            }
        }
    }

#ifdef DEBUG
    std::cout << "Current binds:\n";
    for (const auto& [action, codes] : m_actions) {
        std::cout << "- " << action << ": ";
        for (const auto& code : codes) {
            // Print code...
        }
        std::cout << "\n";
    }
#endif
}
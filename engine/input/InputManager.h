#pragma once
#include "InputTypes.h"
#include <unordered_map>
#include <string>
#include <vector>

// Forward declare GLFWwindow to avoid including glfw3.h
typedef struct GLFWwindow GLFWwindow;

class InputManager {
public:
    InputManager(GLFWwindow* glfWin);

    // Action with multiple possible bindings
    using ActionBinding = std::vector<InputCode>;
    
    void BindAction(const std::string& action, InputCode code);
    void LoadConfig(const std::string& path);
    bool IsActionPressed(const std::string& action) const;

private:
    std::unordered_map<std::string, ActionBinding> m_actions;

    GLFWwindow* window;
};

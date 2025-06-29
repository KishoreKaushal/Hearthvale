#pragma once

struct GLFWwindow; // forward declaration to avoid including GLFW here

namespace Hearthvale {

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void PollEvents();
    bool ShouldClose() const;

private:
    GLFWwindow* mWindow;
};

}

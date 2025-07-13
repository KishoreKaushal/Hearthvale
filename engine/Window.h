#pragma once

struct GLFWwindow; // forward declaration to avoid including GLFW here

namespace Hearthvale {

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void pollEvents();

    void swapBuffers();

    bool shouldClose() const;

    void clear(float r, float g, float b, float a = 1.0f);

    bool isKeyPressed(const int key) const;

    void requestClose() const;

    GLFWwindow* getGLFWWindow() const { return mWindow; }

private:
    GLFWwindow* mWindow;

    static void resizeCallback(GLFWwindow* window, int width, int height);

    void handleResize(int width, int height);

    bool validateGLContext() const;
};
}

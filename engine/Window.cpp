#include <glad.h>           // must come before anything OpenGL-related
#include <GLFW/glfw3.h>     // GLFW uses OpenGL, so this goes second
#include <spdlog/spdlog.h>

#include "Window.h"

#include <iostream>

#include "RenderUtils.h"

namespace Hearthvale {

    Window::Window(int width, int height, const char* title)
    {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW.\n";
            std::exit(EXIT_FAILURE);
        }

        mWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!mWindow) {
            std::cerr << "Failed to create GLFW window.\n";
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(mWindow);
        std::cout << "GLFW window created successfully.\n";

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD!" << std::endl;
        }

        glfwSetWindowUserPointer(mWindow, this);

        glfwSetFramebufferSizeCallback(mWindow, static_cast<GLFWframebuffersizefun>(Window::resizeCallback));
    }

    Window::~Window()
    {
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(mWindow);
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(mWindow);
    }

    void Window::clear(float r, float g, float b, float a)
    {
        RenderUtils::ClearScreen(r, g, b, a);
    }

    bool Window::isKeyPressed(const int key) const
    {
        return glfwGetKey(mWindow, key) == GLFW_PRESS;
    }

    void Window::requestClose() const
    {
        glfwSetWindowShouldClose(mWindow, true);
    }

    void Window::resizeCallback(GLFWwindow* glfwWin, int width, int height)
    {
        Window* windowObj = static_cast<Window*>(glfwGetWindowUserPointer(glfwWin));
        windowObj->handleResize(width, height);
    }

    void Window::handleResize(int width, int height)
    {
        if (!validateGLContext()) return;

        // prevent (0 or negative) sizes
        width = std::max(1, width);
        height = std::max(1, height);

        glViewport(0, 0, width, height);
    }

    bool Window::validateGLContext() const
    {
        auto contextWindow = glfwGetCurrentContext();

        if (!contextWindow) {
            spdlog::error("No OpenGL context active!");
            return false;
        }

        // 2. Verify this window owns the context
        if (contextWindow != mWindow) {
            spdlog::warn("Wrong window context! Expected: {}, Actual: {}",
                        fmt::ptr(mWindow), fmt::ptr(glfwGetCurrentContext()));
            return false;
        }

        // 3. Additional safety checks
        if (glfwWindowShouldClose(mWindow)) {
            spdlog::debug("Window marked for closing");
            return false;
        }

        return true;
    }
}

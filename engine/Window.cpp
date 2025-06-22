#include <glad.h>           // must come before anything OpenGL-related
#include <GLFW/glfw3.h>     // GLFW uses OpenGL, so this goes second
#include "Window.hpp"

#include <iostream>

namespace Hearthvale {

    Window::Window(int width, int height, const char* title) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW.\n";
            std::exit(EXIT_FAILURE);
        }

        m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!m_Window) {
            std::cerr << "Failed to create GLFW window.\n";
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(m_Window);
        std::cout << "GLFW window created successfully.\n";

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD!" << std::endl;
        }
    }

    Window::~Window() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::PollEvents() {
        glfwPollEvents();
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

}

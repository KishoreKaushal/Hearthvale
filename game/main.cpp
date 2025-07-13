#include "Window.h"
#include "input/InputManager.h"

#include <thread> // for std::this_thread::sleep_for
#include <chrono>
#include <iostream>

int main() {
    Hearthvale::Window window(800, 600, "Hearthvale");
    InputManager inputManager(window.getGLFWWindow());

    // Load key bindings from config file
    try {
        inputManager.LoadConfig("C:\\Hearthvale\\config\\input.ini");
    } catch (const std::exception& e) {
        std::cerr << "Error loading input config: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    while (!window.shouldClose()) {
        window.pollEvents();

        if (inputManager.IsActionPressed("Quit")) {
            std::cout << "Quitting!" << std::endl;
            window.requestClose();
        } else if (inputManager.IsActionPressed("MoveForward")) {
            std::cout << "Moving forward!" << std::endl;
            window.clear(0.2f, 0.0f, 0.0f);
        } else if (inputManager.IsActionPressed("MoveBack")) {
            std::cout << "Moving back!" << std::endl;
            window.clear(0.0f, 0.2f, 0.0f);
        } else if (inputManager.IsActionPressed("Jump")) {
            std::cout << "Jumping!" << std::endl;
            window.clear(0.0f, 0.0f, 0.2f);
        } else {
            window.clear(0.1f, 0.1f, 0.1f); // Default background color
        }

        // Temporary: sleep so we don’t hog the CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        window.swapBuffers();
    }

    return 0;
}
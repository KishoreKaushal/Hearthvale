#include "Window.hpp"
#include <thread> // for std::this_thread::sleep_for
#include <chrono>

int main() {
    Hearthvale::Window window(800, 600, "Hearthvale");

    while (!window.ShouldClose()) {
        window.PollEvents();

        // Temporary: sleep so we don’t hog the CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
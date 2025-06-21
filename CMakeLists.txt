cmake_minimum_required(VERSION 3.14)
project(Hearthvale)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Include engine and GLFW headers
include_directories(engine libs/glfw/include)

# Add GLFW manually from submodule
add_subdirectory(libs/glfw)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include engine headers (so game/main.cpp can find Renderer.hpp)
include_directories(engine)

# Collect all engine and game source files (*.cpp)
file(GLOB ENGINE_SRC engine/*.cpp)
file(GLOB GAME_SRC game/*.cpp)

# Define the executable and link sources
add_executable(Hearthvale ${ENGINE_SRC} ${GAME_SRC})

# Link GLFW to your executable
target_link_libraries(Hearthvale PRIVATE glfw)

# Platform-specific linking
if(UNIX AND NOT APPLE)
  # Linux-only system libraries
  target_link_libraries(Hearthvale PRIVATE dl pthread X11 Xrandr Xi Xxf86vm Xcursor)
elseif(APPLE)
  # macOS-only frameworks
  find_library(COCOA_LIBRARY Cocoa)
  find_library(OPENGL_LIBRARY OpenGL)
  find_library(IOKIT_LIBRARY IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)

  target_link_libraries(Hearthvale PRIVATE
          ${COCOA_LIBRARY}
          ${OPENGL_LIBRARY}
          ${IOKIT_LIBRARY}
          ${COREVIDEO_LIBRARY}
  )
endif()
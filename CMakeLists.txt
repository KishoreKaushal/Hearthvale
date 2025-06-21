cmake_minimum_required(VERSION 3.14)
project(Hearthvale)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include engine headers (so game/main.cpp can find Renderer.hpp)
include_directories(engine)

# Collect all engine and game source files (*.cpp)
file(GLOB ENGINE_SRC engine/*.cpp)
file(GLOB GAME_SRC game/*.cpp)

# Define the executable and link sources
add_executable(Hearthvale ${ENGINE_SRC} ${GAME_SRC})

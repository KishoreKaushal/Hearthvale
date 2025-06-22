cmake_minimum_required(VERSION 3.14)
project(Hearthvale)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
endif()

# Add submodules
add_subdirectory(libs/glfw)
add_subdirectory(engine)

# Define the executable and link sources
add_executable(Hearthvale game/main.cpp)

# Link engine to main game 
# internally the engine links to glfw and GLAD
# this is implementation detail which Hearthvale doesn't needs to know
target_link_libraries(Hearthvale PRIVATE engine)
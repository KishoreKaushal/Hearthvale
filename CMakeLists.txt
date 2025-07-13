cmake_minimum_required(VERSION 3.14)
project(Hearthvale)

# ======================
# 0. Find Dependencies
# ======================
find_package(Python3 REQUIRED)  # For keycode generation

# =============================================
# 1. Global Configuration
# =============================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# =============================================
# 2. Third-party Libraries Configuration
# =============================================

# GLFW Configuration
if(NOT TARGET glfw)
  set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  add_subdirectory(libs/glfw)
endif()

# Only configure SPDLOG if not already configured
if(NOT TARGET spdlog)
    set(SPDLOG_COMPILED_LIB OFF CACHE BOOL "Use header-only spdlog" FORCE)
    set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "Disable examples" FORCE)
    set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Disable tests" FORCE)
    add_subdirectory(libs/spdlog)
endif()

# =============================================
# 3. Project Components
# =============================================
add_subdirectory(engine)
add_subdirectory(engine/input)

# Define the executable and link sources
add_executable(Hearthvale game/main.cpp)

# Link engine to main game 
# internally the engine links to glfw and GLAD
# this is implementation detail which Hearthvale doesn't needs to know
target_link_libraries(Hearthvale PRIVATE engine)
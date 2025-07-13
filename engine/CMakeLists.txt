# Collect all engine sources
file(GLOB ENGINE_SRC *.cpp)

# Engine target
add_library(engine ${ENGINE_SRC})

# Dependencies --------------------------------------------------

# 1. GLAD (internal to engine)
add_library(glad STATIC glad/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad)

# 2. External libs (from project root)
# Only link to SPDLOG if engine is the top-level project
if(NOT TARGET spdlog::spdlog_header_only)
    add_subdirectory(${PROJECT_SOURCE_DIR}/libs/spdlog)
endif()

# Linking -------------------------------------------------------
target_link_libraries(engine PRIVATE
  glad           # Internal GLAD
  glfw           # From root CMake
  spdlog::spdlog_header_only  # Header-only SPDLOG
)

# Include paths -------------------------------------------------
target_include_directories(engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}       # Engine headers
    ${CMAKE_CURRENT_SOURCE_DIR}/glad  # GLAD headers
)

# Platform-specific system libraries
if(UNIX AND NOT APPLE)
  target_link_libraries(engine PRIVATE dl pthread X11 Xrandr Xi Xxf86vm Xcursor)
elseif(APPLE)
  find_library(COCOA_LIBRARY Cocoa)
  find_library(OPENGL_LIBRARY OpenGL)
  find_library(IOKIT_LIBRARY IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)

  target_link_libraries(engine PRIVATE
    ${COCOA_LIBRARY}
    ${OPENGL_LIBRARY}
    ${IOKIT_LIBRARY}
    ${COREVIDEO_LIBRARY}
  )
endif()

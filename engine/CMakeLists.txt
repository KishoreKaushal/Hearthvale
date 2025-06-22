# Collect all engine sources
file(GLOB ENGINE_SRC *.cpp)

add_library(engine ${ENGINE_SRC})

# Include path for engine headers
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add GLAD
add_library(glad STATIC glad/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad)

target_link_libraries(engine PRIVATE glad glfw)

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

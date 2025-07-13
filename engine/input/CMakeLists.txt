find_package(Python3 REQUIRED)

# 1. Locate GLFW headers (internal to input module)
set(GLFW_INTERNAL_HEADER 
    "${CMAKE_SOURCE_DIR}/libs/glfw/include/GLFW/glfw3.h"
)

# 2. Verify header exists before generating
if(NOT EXISTS "${GLFW_INTERNAL_HEADER}")
    message(FATAL_ERROR "GLFW headers not found at ${GLFW_INTERNAL_HEADER}")
endif()

# 3. Key code generation (private to input module)
add_custom_command(
    OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/KeyCodeDefines.inl"
    COMMAND ${Python3_EXECUTABLE} 
            "${CMAKE_SOURCE_DIR}/tools/generate_keys.py"
    DEPENDS "${GLFW_INTERNAL_HEADER}"
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    COMMENT "Generating input key codes (GLFW-encapsulated)"
)

# 4. Mark generated file
set_source_files_properties(
    "${CMAKE_CURRENT_SOURCE_DIR}/KeyCodeDefines.inl"
    PROPERTIES GENERATED TRUE
)

# 5. Input library target
add_library(engine_input STATIC
    InputManager.cpp
    "${CMAKE_CURRENT_SOURCE_DIR}/KeyCodeDefines.inl"  # Include generated file
)

target_include_directories(engine_input PRIVATE
    "${CMAKE_SOURCE_DIR}/libs/glfw/include"  # Only visible to input module
)

# 6. Link to main engine (no GLFW exposure)
target_link_libraries(engine PRIVATE
    engine_input
)




# # 1. Key Code Generation
# # Run BEFORE any targets that need the key definitions
# add_custom_command(
#     OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/KeyCodeDefines.inl
#     COMMAND ${Python3_EXECUTABLE} 
#             ${CMAKE_SOURCE_DIR}/tools/generate_keys.py
#     DEPENDS ${GLFW_INCLUDE_DIR}/GLFW/glfw3.h
#     COMMENT "Generating key codes from GLFW"
#     VERBATIM
# )

# # Mark the generated file as a dependency
# set_source_files_properties(
#     ${CMAKE_CURRENT_SOURCE_DIR}/KeyCodeDefines.inl
#     PROPERTIES GENERATED TRUE
# )

# # 2. Library target
# add_library(engine_input STATIC
#     InputManager.cpp
#     InputTypes.h
#     ${CMAKE_CURRENT_SOURCE_DIR}/KeyCodeDefines.inl
# )

# # 3. Dependencies
# target_include_directories(engine_input PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     ${GLFW_INCLUDE_DIRS}
# )

# # 4. Link to main engine
# target_link_libraries(engine PRIVATE engine_input)
cmake_minimum_required(VERSION 3.19)
project(StripForge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Include directories
# -----------------------------
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/scr/headers
    ${CMAKE_SOURCE_DIR}/scr/commands
    ${CMAKE_SOURCE_DIR}/ThirdParty/SDL2/include
    ${CMAKE_SOURCE_DIR}/ThirdParty/imgui
    ${CMAKE_SOURCE_DIR}/ThirdParty/imgui/backends
    ${CMAKE_SOURCE_DIR}/ThirdParty/gl3w/include
)

# -----------------------------
# Source files
# -----------------------------
file(GLOB_RECURSE APP_SOURCES scr/*.cpp)
file(GLOB_RECURSE IMGUI_SOURCES
    ThirdParty/imgui/*.cpp
    ThirdParty/imgui/backends/imgui_impl_sdl2.cpp
    ThirdParty/imgui/backends/imgui_impl_opengl3.cpp
)
file(GLOB_RECURSE GL3W_SOURCES ThirdParty/gl3w/src/gl3w.c)

set(SOURCES
    Main.cpp
    Main.h 
    ${APP_SOURCES}
    ${IMGUI_SOURCES}
    ${GL3W_SOURCES}
)

# -----------------------------
# Executable
# -----------------------------
add_executable(StripForge ${SOURCES})

# -----------------------------
# Link libraries
# -----------------------------
# SDL2 and SDL2main
set(SDL2_LIB_DIR "${CMAKE_SOURCE_DIR}/ThirdParty/SDL2/lib/x64")
target_link_libraries(StripForge
    "${SDL2_LIB_DIR}/SDL2.lib"
    "${SDL2_LIB_DIR}/SDL2main.lib"
    opengl32  # OpenGL on Windows
)

# -----------------------------
# Copy SDL2.dll to build folder
# -----------------------------
add_custom_command(TARGET StripForge POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL2_LIB_DIR}/SDL2.dll"
    $<TARGET_FILE_DIR:StripForge>
)

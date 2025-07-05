cmake_minimum_required(VERSION 3.10.0)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

# Include GLFW headers
include_directories(
    ${CMAKE_SOURCE_DIR}/external/glfw/include
)
include_directories(
    ${CMAKE_SOURCE_DIR}/include()
)

# Link GLFW static library
link_directories(
    ${CMAKE_SOURCE_DIR}/external/glfw/lib
)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(GameEngine ${SOURCES})

# Link GLFW and OpenGL
target_link_libraries(GameEngine glfw3 opengl32)
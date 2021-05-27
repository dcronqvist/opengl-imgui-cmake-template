cmake_minimum_required(VERSION 3.0.0)
project(opengl-imgui-cmake-template VERSION 0.1.0)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

link_directories(libs/glfw)

include_directories(libs/glad)
include_directories(libs/KHR)
include_directories(libs/imgui)
include_directories(libs/glfw)
include_directories(include)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(cpp-opengl ${SOURCES})

find_package(OpenGL REQUIRED)
target_link_libraries(cpp-opengl PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(cpp-opengl PRIVATE glfw3)

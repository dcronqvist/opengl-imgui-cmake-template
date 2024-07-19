cmake_minimum_required(VERSION 3.29)
project(opengl-imgui-cmake-template VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the CMakeModules directory to the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMakeModules")

# Include some custom CMake modules
include(vscode-debug)

# Find GLFW using the custom FindGLFW.cmake module
find_package(GLFW REQUIRED)
find_package(GLAD REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE 
  include
  ${GLAD_INCLUDE_DIRS}
  ${GLFW_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
  ${GLFW_LIBRARIES}
  ${GLAD_LIBRARIES}
)

make_target_debuggable_in_vscode(${PROJECT_NAME})

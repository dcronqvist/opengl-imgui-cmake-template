# FindGLFW.cmake
# A module to find GLFW
#
# This module defines the following variables:
#   GLFW_FOUND - set to true if GLFW is found
#   GLFW_INCLUDE_DIRS - GLFW include directories
#   GLFW_LIBRARIES - GLFW libraries

include(FetchContent)

# Fetch GLFW from GitHub
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
)

# Ensure the content is downloaded
FetchContent_MakeAvailable(glfw)

# Set variables for GLFW
set(GLFW_FOUND TRUE)
set(GLFW_INCLUDE_DIRS ${glfw_SOURCE_DIR}/include)
set(GLFW_LIBRARIES glfw)

# If you need to set specific options for GLFW build, you can do so here
# For example, if you need to disable tests, you can do:
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")

# This part ensures that the GLFW content is properly configured and built
FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)
    # Optionally, if you want to build GLFW as part of your build process
    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

# If using static library, you might want to link necessary system libraries
if(NOT TARGET glfw)
    find_package(OpenGL REQUIRED)
    list(APPEND GLFW_LIBRARIES ${OPENGL_gl_LIBRARY})
endif()

# Provide debug message
message(STATUS "GLFW found: ${GLFW_FOUND}")
message(STATUS "GLFW include directories: ${GLFW_INCLUDE_DIRS}")
message(STATUS "GLFW libraries: ${GLFW_LIBRARIES}")

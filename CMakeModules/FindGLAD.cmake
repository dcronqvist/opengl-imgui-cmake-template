# FindGLAD.cmake
# A module to find GLAD
#
# This module defines the following variables:
#   GLAD_FOUND - set to true if GLAD is found
#   GLAD_INCLUDE_DIRS - GLAD include directories
#   GLAD_LIBRARIES - GLAD libraries

if (NOT TARGET glad)
    # Add the GLAD library
    add_library(glad STATIC
        ${CMAKE_CURRENT_LIST_DIR}/glad/src/gl.cpp
    )

    target_include_directories(glad PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/glad/include
    )

    set(GLAD_FOUND TRUE)
    set(GLAD_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include)
    set(GLAD_LIBRARIES glad)
endif()

# Provide debug message
message(STATUS "GLAD found: ${GLAD_FOUND}")
message(STATUS "GLAD include directories: ${GLAD_INCLUDE_DIRS}")
message(STATUS "GLAD libraries: ${GLAD_LIBRARIES}")

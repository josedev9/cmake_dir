cmake_minimum_required(VERSION 3.20.0)

project(windows VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(USE_LIBRARY "To use a external library defined by the user localy" ON)
option(USE_GLFW "To use the github library imported as a submodule" ON)

if(USE_LIBRARY)
    add_subdirectory(Library)
    list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR/LIBRARY/include}")
    list(APPEND EXTRA_LIBR "${CMAKE_SOURCE_DIR/LIBRARY/src}")
    list(APPEND EXTRA_DIR Library)
endif()

if(USE_GLFW)
    add_subdirectory(external/glfw)
    list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/external/glfw/include")
    list(APPEND EXTRA_LIBR "${CMAKE_SOURCE_DIR}/external/glfw/src")
    list(APPEND EXTRA_DIR glfw)
endif()


add_subdirectory(executable/another_level)

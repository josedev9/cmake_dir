cmake_minimum_required(VERSION 3.12)

project(linux VERSION 2.5.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(USE_LIBR "Use class library" ON)
option(USE_GLFW "Use glfw external library" ON)

if(USE_LIBR)
    add_subdirectory(library)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/library/include")
    list(APPEND EXTRA_LIBS "${PROJECT_SOURCE_DIR}/library/src")
    
    
endif()

if(USE_GLFW)
    add_subdirectory(external/glfw)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/external/glfw/include")
    list(APPEND EXTRA_LIBS "${PROJECT_SOURCE_DIR}/external/glfw/src")
    
endif()


add_subdirectory(executable/something)
add_subdirectory(external/glfw)
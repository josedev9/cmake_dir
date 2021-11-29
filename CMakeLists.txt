cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)


project(optical_flow VERSION 1.0.0)


option(USE_OPENCV "Select this option to link the opencv compiled library" true)
option(USE_LIBR "Select this flag to use the external library created" true)


if(USE_OPENCV)
    set(OpenCV_DIR "C:\\opencv_build\\build")
    message(STATUS "Using the compiled opencv libraries if found")
    find_package(OpenCV REQUIRED)
    if(OPENCV_FOUND)
        message(STATUS "Configuring libraries, opencv has been found locally")
        list(APPEND INCLUDE_DIRS "${OpenCV_INCLUDE_DIRS}")
        list(APPEND INCLUDE_LIB "${OpenCV_LIBS}")
    else()
        message(FATAL_ERROR "Opencv and dependencies couldn't be found aborting")
        
    endif()
    
endif()

if(USE_LIBR)
    message(STATUS "Project configured to use the external library with extra functions")
    add_subdirectory(Libraries)
    list(APPEND INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/Libraries/include")
    list(APPEND INCLUDE_SRC "${CMAKE_SOURCE_DIR}/Libraries/src")
    list(APPEND INCLUDE_LIB Library)
    
endif()


add_subdirectory(main_dir)
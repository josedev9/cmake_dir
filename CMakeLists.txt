cmake_minimum_required(VERSION 3.21)

project(opencv VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(USE_TEMP "Use the temporization library created locally" ON)
option(USE_OPENCV "Use opencv library to compute the camera's captured frames" OFF)


if(USE_TEMP)
    message(STATUS "Using the internal temp library")
    add_subdirectory(Temp)
    list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/Temp/Include" )
    list(APPEND EXTRA_DIRS "${CMAKE_SOURCE_DIR}/Temp/src" )
    list(APPEND EXTRA_LIBS Temp )
     
endif()

if(USE_OPENCV)
    message(status "Using opencv")
    
endif()


add_subdirectory(main_dir/recording)
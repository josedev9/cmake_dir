cmake_minimum_required(VERSION 3.20.0)

project(windows VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(USE_LIBRARY "To use a external library defined by the user localy" ON)
option(USE_GLFW "To use the github library imported as a submodule" ON)
#Configuring the submodules

find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    
#update the submodules as needed
    option(GIT_SUBMODULE "Check submodules during the build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive 
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
        
        
    endif()
    
endif()



#Check all of the submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "glfw submodule was not downloaded! GIT_SUBMODULE was turned off or failed.")

endif()

#END OF SUBMODULES CONFIGURATION


#Finding libraries part
#[[find_library(glew_lib glew NAMES glew2 GLEW GLEW2 DOC "glew library")
#For this example the REQUIRED keyword will not be used, even thought it is included with this cmake version
if(${glew_lib} STREQUAL glew_lib-NOTFOUND)
    message(FATAL_ERROR "glew not found in the system")
else()
    message(STATUS "library found while building")

endif()
]]


#Looking for glew with the binaries installed locally
find_library(glew_libr glew NAMES GLEW2 GLEW glew2 glew32 glew32s
    PATHS "C:\\Users\\10655707\\Desktop\\glew-2.1.0"
    PATH_SUFFIXES 
        "lib\\release\\x64"
        "bin\\release\\x64"
    DOC "glew library")

#Since no required is used manually check if found and add it to the appends
if(${glew_libr} STREQUAL glew_libr-NOTFOUND)
    message(FATAL_ERROR "library not found, can't complete the configuration")
else()
    message(STATUS "glew library found in the system")
    list(APPEND EXTRA_INCLUDES "C:\\Users\\10655707\\Desktop\\glew-2.1.0\\include")
    list(APPEND EXTRA_DIR "${glew_libr}")
    
endif()






if(USE_LIBRARY)
    add_subdirectory(Library)
    list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR/Library/include}")
    list(APPEND EXTRA_LIBR "${CMAKE_SOURCE_DIR/Library/src}")
    list(APPEND EXTRA_DIR Library)
endif()

if(USE_GLFW)
    add_subdirectory(external/glfw)
    list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/external/glfw/include")
    list(APPEND EXTRA_LIBR "${CMAKE_SOURCE_DIR}/external/glfw/src")
    list(APPEND EXTRA_DIR glfw)
endif()


add_subdirectory(executable/another_level)

#Adding the CPack part into the project
include(InstallRequiredSystemLibraries)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/License.txt")
set(CPACK_VERSION_MAJOR "${${PROJECT_NAME}_VERSION_MAJOR}")
set(CPACK_VERSION_MINOR "${${PROJECT_NAME}_VERSION_MINOR}")
include(CPack)
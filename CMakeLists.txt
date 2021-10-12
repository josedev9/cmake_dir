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

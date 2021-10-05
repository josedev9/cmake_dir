cmake_minimum_required(VERSION 3.12.0)
project(anotha_one VERSION 1.0.0)
add_executable(${PROJECT_NAME} main.cpp)

#DOWNLOAD ALL THE SUBMODULES
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



add_subdirectory(Add) 
add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_SOURCE_DIR}/Add/include"
    PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw/include")
target_link_directories(${PROJECT_NAME} 
    PRIVATE "{PROJECT_SOURCE_DIR}/Add/src"
    PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw/src")
target_link_libraries(${PROJECT_NAME} Add glfw)
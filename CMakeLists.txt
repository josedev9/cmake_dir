cmake_minimum_required(VERSION 3.12.0)
project(anotha_one VERSION 1.0.0)

#configuring the versioning 
configure_file(config.h.in config.h)

#Adding the Add library as an option
option(USE_ADD "Use the example included library" ON)
option(USE_GLFW "Use glfw" ON)

add_executable(${PROJECT_NAME} main.cpp)

#add the binaries library to the source code
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

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

endif()


#If the library is added include the dependencies required
if(USE_ADD)
    add_subdirectory(Add)
    target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/Add/include")
    target_link_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/Add/Src")  
    target_link_libraries(${PROJECT_NAME} Add)  
endif()
if(USE_GLFW)
    add_subdirectory(external/glfw)
    target_include_directories(${PROJECT_NAME} 
        PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw/include")
    target_link_directories(${PROJECT_NAME} 
        PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw/src")   
    target_link_libraries(${PROJECT_NAME} glfw)
endif()
cmake_minimum_required(VERSION 3.12)

project(linux VERSION 2.5.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)


#Find libraries configuration
#find_library()




option(USE_LIBR "Use class library" ON)
option(USE_GLFW "Use glfw external library" ON)
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


if(USE_LIBR)
    add_subdirectory(library)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/library/include")
    list(APPEND EXTRA_LIBS "${PROJECT_SOURCE_DIR}/library/src")
    list(APPEND EXTRA_MORE library)
    
endif()

if(USE_GLFW)
    add_subdirectory(external/glfw)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/external/glfw/include")
    list(APPEND EXTRA_LIBS "${PROJECT_SOURCE_DIR}/external/glfw/src")
    list(APPEND EXTRA_MORE glfw)
endif()


add_subdirectory(executable/something)

#Installing files configuration
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/executable/something/configure/configure.h" DESTINATION include)

#Installing using cpack

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Linux_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Linux_VERSION_MINOR}")
include(CPack)
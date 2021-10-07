add_executable(${PROJEC_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_BINARY_DIR}/executable/something/configure"
    PUBLIC EXTRA_INCLUDES)
target_link_libraries(${PROJECT_NAME}
    PUBLIC EXTRA_LIBR)

if(USE_LIBR)
    target_link_libraries(${PROJECT_NAME} library)  
endif()


if(USE_GLFW)

    target_link_libraries(${PROJECT_NAME} glfw)

    endif()

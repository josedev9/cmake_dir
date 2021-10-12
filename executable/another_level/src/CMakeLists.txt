add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME}
    PUBLIC "${CMAKE_BINARY_DIR}/executable/another_level/configure"
    PUBLIC "${EXTRA_INCLUDES}")
target_link_directories(${PROJECT_NAME}
    PUBLIC "${EXTRA_LIBR}")
target_link_libraries(${PROJECT_NAME} "${EXTRA_DIR}")
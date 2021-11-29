add_executable(${PROJECT_NAME} main.cpp)


target_include_directories(${PROJECT_NAME} 
    PUBLIC "${CMAKE_BINARY_DIR}/main_dir/configure"
    PUBLIC "${INCLUDE_DIRS}")
target_link_directories(${PROJECT_NAME} PUBLIC "${INCLUDE_SRC}")


target_link_libraries(${PROJECT_NAME} "${INCLUDE_LIB}")

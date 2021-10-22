add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} 
    PUBLIC "${CMAKE_BINARY_DIR}/main_dir/recording/config_file"
    PUBLIC "${EXTRA_INCLUDES}")

target_link_directories(${PROJECT_NAME} PUBLIC "${EXTRA_DIRS}")

target_link_libraries(${PROJECT_NAME} "${EXTRA_LIBS}")
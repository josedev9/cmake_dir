cmake_minimum_required(VERSION 3.12.0)
project(anotha_one VERSION 1.0.0)
add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(Add)
#[[target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/Add")]]
target_link_directories(${PROJECT_NAME} PRIVATE "{PROJECT_SOURCE_DIR}/Add")
target_link_libraries(${PROJECT_NAME} Add)
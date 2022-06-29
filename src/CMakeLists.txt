add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}) # For configure.h access
message(STATUS "Creating configure.h file for macros")
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_SOURCE_DIR}/include
        PUBLIC "${INCLUDE_DIRS}")
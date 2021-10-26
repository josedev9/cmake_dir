add_executable(${PROJECT_NAME} main.cpp)

if(USE_OPENCV)
    message(STATUS "Using opencv")
    set(OpenCV_DIR "C:\\OpenCV-MinGW-Build-OpenCV-4.5.2-x64")
    find_package(OpenCV REQUIRED)
    list(APPEND EXTRA_LIBS ${OpenCV_LIBS})
    list(APPEND EXTRA_INCLUDES "${OpenCV_DIR}/include")
    
endif()
target_include_directories(${PROJECT_NAME} 
    PUBLIC "${CMAKE_BINARY_DIR}/main_dir/recording/config_file"
    PUBLIC "${EXTRA_INCLUDES}")

target_link_directories(${PROJECT_NAME} PUBLIC "${EXTRA_DIRS}")

target_link_libraries(${PROJECT_NAME} "${EXTRA_LIBS}")

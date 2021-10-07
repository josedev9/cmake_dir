add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_BINARY_DIR}/executable/something/configure"
    PUBLIC ${EXTRA_INCLUDES})
target_link_directories(${PROJECT_NAME}
    PUBLIC ${EXTRA_LIBS})

target_link_libraries(${PROJECT_NAME} ${EXTRA_MORE})
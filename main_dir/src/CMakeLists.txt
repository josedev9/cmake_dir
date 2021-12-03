#add_executable(${PROJECT_NAME} main.cpp)
#add_executable(reading_and_displaying_images reading_and_displaying_images.cpp)
aux_source_directory(. SRC_FILES)
#Creation of the cpp parser function
function(cpp_parser)
    foreach(src_cpp ${SRC_FILES})
        string(REGEX REPLACE "^./" "" src "${src_cpp}")
        string(REGEX REPLACE ".cpp" "" src "${src}")
        message(STATUS "Element: ${src_cpp} ${src}")
        add_executable(${src} ${src_cpp})
        target_include_directories(${src} 
            PUBLIC "${CMAKE_BINARY_DIR}/main_dir/configure"
            PUBLIC "${INCLUDE_DIRS}")

        target_link_directories(${src} PUBLIC "${INCLUDE_SRC}")


        target_link_libraries(${src} "${INCLUDE_LIB}")   
    endforeach()
endfunction()

cpp_parser()





#For other executable files
#[[target_include_directories(reading_and_displaying_images 
    PUBLIC "${CMAKE_BINARY_DIR}/main_dir/configure"
    PUBLIC "${INCLUDE_DIRS}")
    
target_link_directories(reading_and_displaying_images PUBLIC "${INCLUDE_SRC}")

1
target_link_libraries(reading_and_displaying_images "${INCLUDE_LIB}")]]

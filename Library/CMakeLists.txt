add_library(Library include/file.h src/file.cpp)

if(USE_LIBRARY)
    target_include_directories(Library "${CMAKE_SOURCE_DIR}/Library/include")
endif()

add_library(Library include/library.h src/library.cpp)
if(USE_LIBR)
    target_include_directories(Library PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
endif()
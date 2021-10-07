add_library(library src/file.cpp)
if(USE_LIBR)
    target_include_directories(library PUBLIC "${PROJECT_SOURCE_DIR}/library/include")
endif()
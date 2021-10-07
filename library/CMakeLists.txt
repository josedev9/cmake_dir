add_library(library src/file.cpp include/file.h)
if(USE_LIBR)
    target_include_directories(library PUBLIC "${PROJECT_SOURCE_DIR}/library/include")
endif()

install(TARGETS library DESTINATION lib)
install(FILES include/file.h DESTINATION include)
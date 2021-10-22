add_library(Temp src/temp.cpp Include/temp.h)

if(USE_TEMP)
    target_include_directories(Temp PUBLIC "${CMAKE_SOURCE_DIR}/Temp/Include")
endif()

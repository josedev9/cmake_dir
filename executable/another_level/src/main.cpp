#include <iostream>

#include "configure.h"

#ifdef USE_LIBRARY
#   include "file.h"
#endif

#ifdef USE_GLFW
#   include "GLFW/glfw3.h"
#endif

int main(int argc, char const * argv[]){
    std::cout<<"The file called '"<<argv[0]<<"' has the following versions: "<<windows_VERSION_MAJOR<<" and "<<windows_VERSION_MINOR<<std::endl;
    File *ptr=new File("Test object",300);
    ptr->get_num();

    return 0;
}
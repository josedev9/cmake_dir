#include <iostream>
#include "configure.h"

#ifdef USE_OPENCV
    #include "opencv2/opencv.hpp"
#endif

#ifdef USE_LIBR
    #include "library.h"
#endif

int main(int argc, const char * argv[]){
    //Testing the state of the cmake project
    std::cout<< "File named " << argv[0] <<" executed with versions Major " <<optical_flow_VERSION_MAJOR<<" and Minor "<<optical_flow_VERSION_MAJOR <<std::endl;
    print_version();
    return 0;
}
#include <iostream>
#include "config.h"
#ifdef USE_TEMP
#   include "temp.h"
#endif

#ifdef USE_OPENCV
//Include something
#endif

int main(int argc, char const *argv[])
{
    std::cout<<"Name of the current active executable:  "<<argv[0]<<" Versions control: MAX->"<<opencv_VERSION_MAJOR<<" MIN->"<<opencv_VERSION_MINOR<<std::endl;

    #ifdef USE_TEMP
        create_defined_temporization(10.0,1.0,printxx);
    #endif
    return 0;
}


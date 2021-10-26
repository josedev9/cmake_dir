#include <iostream>
#include "config.h"
#ifdef USE_TEMP
#   include "temp.h"
#endif

#ifdef USE_OPENCV
#   include"opencv2/opencv.hpp"
#endif

int main(int argc, char const *argv[])
{
    std::cout<<"Name of the current active executable:  "<<argv[0]<<" Versions control: MAX->"<<opencv_VERSION_MAJOR<<" MIN->"<<opencv_VERSION_MINOR<<std::endl;

    #ifdef USE_OPENCV
        cv::Mat image=cv::imread("C:\\Users\\10655707\\Desktop\\spot_painting.jpg");

        if(image.empty()){std::cout<<"Error opening the image"<<std::endl;std::cin.get();return -1;}

        std::string windowname="Example";
        
        cv::namedWindow(windowname);
        cv::imshow(windowname,image);
        cv::waitKey(0);
        cv::destroyWindow(windowname);
    #endif

    #ifdef USE_TEMP
        create_defined_temporization(10.0,1.0,getDateandTime);
    #endif
    return 0;
}


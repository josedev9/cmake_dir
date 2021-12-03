
#include <iostream>
#include "configure.h"

#ifdef USE_OPENCV
#   include "opencv2/opencv.hpp"
#endif


int main(int argc, const char *argv[]){
    cv::Mat img_greyscale=cv::imread("C:\\Users\\10655707\\Desktop\\optical-flow\\input-image.jpg",0);
    cv::imshow("greyscale read from file",img_greyscale);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
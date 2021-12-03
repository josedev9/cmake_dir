#include <iostream>
#include "configure.h"
#include <vector>
#ifdef USE_OPENCV
#   include "opencv2/opencv.hpp"
#endif
#ifdef USE_LIBR
#   include "excep.h"
#endif

int main(int argc, char const *argv[]){
    cv::Mat frame_origin=cv::imread("C:\\Users\\10655707\\Desktop\\optical-flow\\input-image.jpg");
    //First part with basic interpolation and without concat
    /* cv::imshow("original frame",frame_origin);
    int width=300, height=200, width_up=640, height_up=480;
    cv::Mat frame_down,frame_up;
    cv::resize(frame_origin,frame_down,cv::Size(width,height),cv::INTER_LINEAR);
    cv::imshow("downsized image",frame_down);
    cv::resize(frame_origin,frame_up,cv::Size(width_up,height_up),cv::INTER_LINEAR);
    cv::imshow("image up",frame_up);
    cv::waitKey(0);
    cv::destroyAllWindows(); */
    //Second part with interpolations and concat
    cv::Mat a, b;
    std::vector <cv::Mat> image_collector;
    for(size_t i=0;i<3;i++){
        cv::Mat add;
        image_collector.push_back(add);
        int j=i;
        if(i!=0){j+=1;}
        cv::resize(frame_origin,image_collector.at(i),cv::Size(640,480),j);}
    cv::hconcat(image_collector.at(0),image_collector.at(1),a);
    cv::hconcat(a,image_collector.at(2),b);
    cv::imshow("Concatenated images",b);
    cv::waitKey(0);
    return 0;
}
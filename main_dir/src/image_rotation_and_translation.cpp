#include <configure.h>

#ifdef USE_OPENCV
#   include "opencv2/opencv.hpp"
#endif

int main(int argc, char const *argv[]){
    cv::Mat image=cv::imread("C:\\Users\\10655707\\Desktop\\optical-flow\\input-image.jpg");
    cv::Point2f center((image.cols-1)/2.0,(image.rows-1)/2.0);
    cv::Mat rotation_matrix=cv::getRotationMatrix2D(center,45.0,1.0);
    cv::Mat rotated_image;
    cv::warpAffine(image,rotated_image,rotation_matrix,image.size());
    cv::hconcat(image,rotated_image,image);
    cv::imshow("Output",image);
    int key=cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
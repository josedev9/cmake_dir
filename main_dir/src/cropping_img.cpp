#include <iostream>
#include "configure.h"

#ifdef USE_OPENCV
#   include "opencv2/opencv.hpp"
#endif

int main(int argc, char const *argv[]){
    /* cv::Mat combined;
    cv::Mat img=cv::imread("C:\\Users\\10655707\\Desktop\\optical-flow\\input-image.jpg");
    std::cout<<"width: "<<img.size().width<<" height: "<<img.size().height<<" channels: "<<img.channels()<<std::endl;
    cv::Mat cropped=img(cv::Range(175,682),cv::Range(200,780));
    cv::imshow("Normal",img);
    cv::imshow("cropped",cropped);
    cv::waitKey(0);
    cv::destroyAllWindows(); */

    //Cropping into small patches with opencv
    cv::Mat image_input=cv::imread("C:\\Users\\10655707\\Desktop\\optical-flow\\input-image.jpg");
    cv::Mat image=image_input.clone();
    int width=image_input.cols,height=image_input.rows;
    std::cout<<"Width "<<width<<" Height "<<height<<std::endl;

    int M=76, N=104, x1=0, y1=0;

    //In theory make patches of MxN size
    for(int y=0;y<height;y+=M){
        for(int x=0;x<width;x+=N){
            if((width-x)<N || (height-y)<M){break;}
            y1=y+M;
            x1=x+N;
            std::string a=std::to_string(x);
            std::string b=std::to_string(y);

            if(x1 > width && y1 > height){
                x=width-1;
                x1=width-1;
                y=width-1;
                y1=width-1;
                cv::Mat tiles=image(cv::Range(y,height),cv::Range(x,width));
                cv::rectangle(image_input,cv::Point(x,y),cv::Point(x1,y1),cv::Scalar(0,0,255),1);
            }

            else if(y1>height){
                y=height-1;
                y1=height-1;
                cv::Mat tiles=image(cv::Range(y,height),cv::Range(x,x+N));
                cv::rectangle(image_input,cv::Point(x,y),cv::Point(x1,y1),cv::Scalar(0,0,255),1);
            }

            else if(x1>width){
                x=width-1;
                x1=width-1;
                cv::Mat tiles=image(cv::Range(y,y+M),cv::Range(x,width));
                cv::rectangle(image_input,cv::Point(x,y),cv::Point(x1,y1),cv::Scalar(0,0,255),1);
            }
            else{
                cv::Mat tiles = image(cv::Range(y, y+M), cv::Range(x, x+N));
                cv::rectangle(image_input, cv::Point(x,y), cv::Point(x1,y1), cv::Scalar(0,255,0), 1); 
            }
        }
    }
    cv::imshow("Something",image_input);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
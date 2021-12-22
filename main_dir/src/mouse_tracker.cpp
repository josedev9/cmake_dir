#include <iostream>
#include <configure.h>
#include <sstream>

#ifdef USE_OPENCV
#   include <opencv2/opencv.hpp>
#endif
cv::Mat frame,frame_reset,aux,aux1,aux2;
cv::Point begin_point_entry,end_point_entry,begin_point_exit,end_point_exit,entry_point_vec1,entry_point_vec2,exit_point_vec1,exit_point_vec2;
int key=0;
const std::string window_name{"Scene configuration"};


void draw_line(int action, int x, int y, int flags, void *userdata){
    if(action==cv::EVENT_LBUTTONDOWN){
        if(key=='1'){
            frame=frame_reset.clone();
            begin_point_entry=cv::Point(x,y);
            cv::circle(frame,begin_point_entry,5,cv::Scalar(255,0,0),-1);
            aux=frame.clone();}
        else if(key=='2'){
            frame=aux.clone();
            end_point_entry=cv::Point(x,y);
            cv::circle(frame,end_point_entry,5,cv::Scalar(255,0,0),-1);
            if(!begin_point_entry.x && !begin_point_entry.y){throw 1;}
            try{cv::line(frame,begin_point_entry,end_point_entry,cv::Scalar(0,0,255),2,8);}
            catch(int num){std::cout<<"Problem"<<std::endl;exit(0);}
            aux1=frame.clone();
        }
        else if(key=='3'){
            frame=aux1.clone();
            entry_point_vec1=cv::Point(x,y);
            cv::circle(frame,entry_point_vec1,5,cv::Scalar(255,255,0),-1);
            aux2=frame.clone();
        }
        else if(key=='4'){
            frame=aux2.clone();
            entry_point_vec2=cv::Point(x,y);
            cv::circle(frame,entry_point_vec2,5,cv::Scalar(255,255,0),-1);
            cv::imshow(window_name,frame);
        }
    }
        cv::imshow(window_name,frame);

    
}


int main(int argc, char **argv){
    frame=cv::imread("scene_image.jpg");
    if(!frame.data){std::cout<<"Can't open the scene image"<<std::endl;return 1;}
    frame_reset=frame.clone();
    cv::namedWindow(window_name);
    cv::setMouseCallback(window_name,draw_line);
    while(key!='q'){
        cv::imshow(window_name,frame);
        key=cv::waitKey(0);
        
        if(key=='c'){
            frame=frame_reset.clone();
        }
    }
    frame.release();
    cv::destroyAllWindows();
    return 0;
}
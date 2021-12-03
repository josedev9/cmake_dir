#include "configure.h"
#include <iostream>

#ifdef USE_OPENCV
#   include "opencv2/opencv.hpp"
#endif

#ifdef USE_LIBR
#   include "excep.h"
#endif

int main(int argc, char const * argv[]){
    #ifdef USE_FILE
        cv::VideoCapture cap("C:\\Users\\10655707\\Downloads\\file.mp4");
        try{if (!cap.isOpened()){throw OpeningVideoError();}}
        catch(const OpeningVideoError &exc){std::cout<<exc.what()<<std::endl;}
        int fps=cap.get(cv::CAP_PROP_FPS);
        std::cout<<"Frames detected in mp4 file: "<<fps<<std::endl;
        while(cap.isOpened()){
            cv::Mat frame;
            bool success=cap.read(frame);
            if(success){cv::imshow("Example of mp4 file",frame);}
            else{std::cout<<"Someting went wrong"<<std::endl;break;}
            int key=cv::waitKey(20);

            if(key=='q'){std::cout<<"Exiting app, pressed q! "<<std::endl;break;}

        }
        cap.release();
        cv::destroyAllWindows();
        
        
        return 0;
    #endif


    #ifdef USE_WEBCAM
        //Videocapture classes definition
        cv::VideoCapture cap(0);
        try{if(!cap.isOpened()){throw OpeningVideoError();}}
        catch(OpeningVideoError &exc){std::cout<<exc.what()<<std::endl;}
        cv::Size frames_size(static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH)),static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT)));
        cv::VideoWriter write("C:\\Users\\10655707\\Downloads\\output.avi",cv::VideoWriter::fourcc('M','J','P','G'),15,frames_size);

        while(cap.isOpened()){
            cv::Mat frame;
            bool success=cap.read(frame);
            if(success){
                cv::imshow("Window",frame);
                write.write(frame);
            }
            else{std::cout<<"Something went wrong while processing the video"<<std::endl;break;}
            int key=cv::waitKey(10);
            if(key=='q'){std::cout<<"Ending the saving and displaying"<<std::endl;break;}
        }
        cap.release();
        write.release();
        cv::destroyAllWindows();
        return 0;
    #endif
}
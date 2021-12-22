#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <iomanip>
#include <configure.h>
#include <chrono>

#ifdef USE_OPENCV
#   include <opencv2/opencv.hpp>
#endif

std::string PATH{"C:\\Users\\10655707\\Desktop\\deepstream_counter_second_step"},Entry{"line-crossing-Entry"},Exit{"line-crossing-Exit"};

class FileOpeningError : public std::exception{
public:
    FileOpeningError() noexcept=default;
    virtual ~FileOpeningError() noexcept=default;
    virtual const char* what() const noexcept{return "File opening exception reached, check the path again in case of not displaying anything";}
};


void ask_for_params(char type,std::ofstream &output){
    std::string complete,out;
    switch (type)
    {
    case 'E':
        complete="Entrance";
        break;
    
    default:
        complete="Exit";
        break;
    }
    for(size_t i=0;i<8;i++){
        std::cout<<"Introduce the "<<i+1<<" value for the counting line of the "<<complete<<": "<<std::flush;
        std::cin>>out;
        if(i!=7){output<<out+";"<<std::flush;}
        else{output<<out<<std::endl;}
        } 
}


void capture_initial_frame(){
    //Capturing initial frame part
    int count=0;
    cv::VideoCapture cap(0);
    cv::Mat frame;
    cv::Size frame_size(640,480);
    if(!cap.isOpened()){std::cout<<"Opening webcam error encountered, closing app"<<std::endl;return;}
    std::cout<<"Discarding initial frames ... "<<std::endl;
    while (count<5)
    {
        bool success=cap.read(frame);
        if (!success){std::cout<<"Camera is not grabing frames correctly, closing app"<<std::endl;break;}
        else{
            int key=cv::waitKey(20);
            count++;
        }
    }
    cv::resize(frame,frame,frame_size,cv::INTER_AREA);
    cv::imwrite("scene_image.jpg",frame);
    cv::imshow("Frame captured",frame);
    cv::waitKey(0);
    cap.release();
    cv::destroyAllWindows();
}

bool check_if_file_exists(){
    std::fstream filename{"scene_image.jpg"};
    if (!filename.is_open()){std::cout<<"File not found run the command again adding the '-c' flag at the end to generate it"<<std::endl;return false;}
    else{std::cout<<"Scene configuration file found"<<std::endl;return true;}
}


void inputArgumentParser(int argc, char const *argv[]){
    for(int i=0;i<argc;i++){
        std::string arg=argv[i];
        if(arg == "-c"){
            std::cout<<"Generating scene file..."<<std::endl;
            capture_initial_frame();
            exit(0);
        }
        if(arg == "--help" || arg == "-h"){std::cout<<"Usage:\n\t\t1.name_of_the_script to configure the scene configuration."
        "\n\t\t2.name_of_the_script -c to capture a frame and use it as reference for the scene configuration.\n\t\t"
        "3.name_of_the_script --help to display help menu."<<std::endl;}
    }
}


int main(int argc, char const *argv[])
{
    inputArgumentParser(argc,argv);
    if(!check_if_file_exists()){return 1;}
    std::string output{};
    std::fstream file{PATH+"\\counter\\config_nvdsanalytics.txt"};
    std::ofstream new_file{PATH+"\\counter\\config_nvdsanalytics_new.txt",std::ios::app};
    if(!file.is_open()){throw FileOpeningError();}
    if(!new_file.is_open()){throw FileOpeningError();}

    try{
        while(std::getline(file,output)){
            if(output.substr(0,Entry.length())==Entry){
                new_file<<output.substr(0,Entry.length())<<"=";
                ask_for_params('E',new_file);}
            else if(output.substr(0,Exit.length())==Exit){
                new_file<<output.substr(0,Exit.length())<<"=";
                ask_for_params('X',new_file);}
            else{new_file<<output<<std::endl;}
        }
        file.close();
        new_file.close();
        /* std::remove("C:\\Users\\10655707\\Desktop\\deepstream_counter_second_step\\counter\\config_nvdsanalytics.txt");
        std::rename("C:\\Users\\10655707\\Desktop\\deepstream_counter_second_step\\counter\\config_nvdsanalytics_new.txt","C:\\Users\\10655707\\Desktop\\deepstream_counter_second_step\\counter\\config_nvdsanalytics.txt");
        std::remove("C:\\Users\\10655707\\Desktop\\deepstream_counter_second_step\\counter\\config_nvdsanalytics_new.txt"); */
        }
    catch(FileOpeningError &exception){std::cout<<exception.what()<<std::endl;}
    return 0;
}
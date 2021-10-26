#include <iostream>
#include "temp.h"
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <sstream>

bool create_defined_temporization(double time,double wait_time,std::string (*func)()){
    auto init=std::chrono::high_resolution_clock::now();
    while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-init).count()<time*1000){
        std::cout<<"Current date and time: " <<(*func)()<<std::endl;
        Sleep(wait_time*1000);
        }
    return true;
} 

std::string getDateandTime(){
    std::time_t tt=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct std::tm *ptm=std::localtime(&tt);
    std::stringstream ss{};
    ss<<std::put_time(ptm,"%Y_%m_%d_%H_%M_%S")<<".png";
    return ss.str();
}


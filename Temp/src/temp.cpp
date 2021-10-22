#include <iostream>
#include "temp.h"
#include <Windows.h>

bool create_defined_temporization(double time,double wait_time,void (*func)(int i)){
    auto init=std::chrono::high_resolution_clock::now();
    int count=1;
    while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-init).count()<time*1000){
        (*func)(count);
        Sleep(wait_time*1000);
        count++;
    }
    return true;
} 

void printxx(int i){
    std::cout<<"Number inputted is: "<<i<<std::endl;
}

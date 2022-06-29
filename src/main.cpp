//
// Created by jose on 30/06/22.
//
#include "iostream"
#include "Cpp_Sandbox.h"
#include "configure.h"

int main(int argc, const char *argv[]){
    std::cout<<"Project information, testing macro configuration: version major->"<<Cpp_Sandbox_VERSION_MAJOR<<
    "version minor->"<<Cpp_Sandbox_VERSION_MINOR<<std::endl;
    // Testing linking of header files
    print();
    return 0;
}
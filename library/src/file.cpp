#include <iostream>
#include "file.h"

File::File(std::string name , int num):name{name},num{num}{}
File::~File()=default;
void File::get_num(){std::cout<<"The class named "<<name<<" has the following value stored inside "<<num<<std::endl;}
#include <iostream>
#include "file.h"

File::File(std::string name, int num):name{name},num{num}{}
File::~File()=default;
void File::get_num(){std::cout<<"The value stored inside the file "<<name <<" is : "<<num<<std::endl;}
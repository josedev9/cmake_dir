#ifndef __FILE_H__
#define __FILE_H__
#include <iostream>
class File
{
private:
    std::string name;
    int num;
public:
    File(std::string name, int num);
    ~File();
    void get_num();
};



#endif // __FILE_H__
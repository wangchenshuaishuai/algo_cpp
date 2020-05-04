#ifndef _EXCEP_H
#define _EXCEP_H

#include <string>
class Excep{
public:
    std::string info;
    Excep(const char *str){
        info = std::string(str);
    }
    ~Excep(){};
};

#endif
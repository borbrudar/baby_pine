#include "ErrorLogger.h"
#include <string>
#include <iostream>

void ErrorLogger::error(int line, std::string message)
{
    report(line,"",message);    
}

void ErrorLogger::report(int line, std::string where, std::string message)
{
    std::cout<<"[line "<<line<<"] Error "<<where<<": "<<message<<std::endl;
    hadError=true;
}

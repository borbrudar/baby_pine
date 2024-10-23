#pragma once
#include <string>

class ErrorLogger{
    public:
    void error(int line,std::string message);
    bool hadError = false;
private:
    void report(int line,std::string where, std::string message);
};


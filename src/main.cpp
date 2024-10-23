#include <bits/stdc++.h>
#include "ErrorLogger.h"
#include "Scanner.h"

ErrorLogger logger;

void run(std::string source){
    Scanner scanner = Scanner(source);
    std::vector<Token> tokens = scanner.scanTokens();


    for(Token token : tokens)
        std::cout<<token<<" ";
}

void runFile(std::string path){
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    run(buffer.str());
    if (logger.hadError) exit(65);
}


void runPrompt(){
    std::string line;
    while(true){
        std::cout<<"> ";
        std::string line;
        getline(std::cin,line);
        if(line == "") break;
        run(line);
        logger.hadError = false;
    }
}


int main(int argc, char** argv){
    if(argc > 2){
        std::cout<<"Too many arguments\n";
        exit(64);
    }
    else if(argc == 2){
        runFile(argv[1]);
    }
    else{
        runPrompt();
    }
}
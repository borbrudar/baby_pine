#include <bits/stdc++.h>

bool hadError = false;

void report(int line,std::string where, std::string message){
    std::cout<<"[line "<<line<<"] Error "<<where<<": "<<message<<std::endl;
    hadError=true;
}

void error(int line,std::string message){
    report(line,"",message);
}

void run(std::string code){
    std::cout<<code<<std::endl;

}

void runFile(std::string path){
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    run(buffer.str());
    if (hadError) exit(65);
}


void runPrompt(){
    std::string line;
    while(true){
        std::cout<<"> ";
        std::string line;
        getline(std::cin,line);
        if(line == "") break;
        run(line);
        hadError = false;
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
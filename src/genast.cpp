#include <bits/stdc++.h>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
static inline void trim(std::string &s) {
    // Trim from start
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    // Trim from end
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void defineAST(std::string path, std::string baseName, std::vector<std::string> types){
    std::ofstream file;
    file.open(baseName + ".h");
    file<<"#pragma once\n";
    file<<"#include <bits/stdc++.h>\n";
    file<<"#include \"Token.h\"\n";
    file<<"class "<<baseName<<"{\n};";

    for(auto u : types){
        std::string className = u.substr(0, u.find(":")-1);
        std::string fields_s = u.substr(u.find(":")+1);
        std::vector<std::string> fields = split(fields_s, ',');
        file<<"\n\nclass "<<className<<" : public "<<baseName<<"{\n";
        file<<"public:\n";
        file<<"    "<<className<<"(";
        for(int i = 0; i <fields.size();i++){
            file<<fields[i];
            if(i != fields.size()-1) file<<", ";
        }
        file<<"){\n";
        for(auto u: fields){
            trim(u);
            std::string name = u.substr(u.find(" ")+1);
            file<<"        this->"<<name<< " = "<<name<<";\n";
        }
        file<<"}\n";
        for(auto u: fields){
            file<<u<<";\n";
        }
        file<<"};";
    }

}

int main(int argc, char** argv){
    std::string out;
    if(argc == 2){
        out = argv[1];
    }else {
        std::cout<<"Invalid usage, specify directory to gen ast to.\n";
        return 1;
    }
    defineAST(out, "Expr", {
        "Binary : Expr left, Token op, Expr right", 
        "Grouping : Expr expression", 
        "Literal : Expr value", 
        "Unary : Token op, Expr right"
    });
}
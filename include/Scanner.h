#pragma once
#include <bits/stdc++.h>
#include "Token.h"
#include "ErrorLogger.h"

class Scanner{
    public:
    Scanner(std::string source);
    std::vector<Token> scanTokens();


private:
    bool isAtEnd();
    void scanToken();

    char advance();
    void addToken(TokenType type);
    void addToken(TokenType, std::string _literal); 
    void addToken(TokenType type, double number_literal);
    bool match(char expected);
    char peek();
    char peekNext();
    void string();
    void number();
    bool isdigit(char c);

    std::string source;
    std::vector<Token> tokens;
    int start=0,current=0,line=1;
    ErrorLogger logger;
};
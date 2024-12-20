#pragma once
#include <bits/stdc++.h>

enum TokenType {
    // single characters
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
    // one or two characters
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // literals
    IDENTIFIER, STRING, NUMBER,

    // keywords
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    // end of file
    EF,

    // dummy for string stuff
    TOKEN_COUNT
};

const std::string toName[TOKEN_COUNT] = {
    // single characters
    "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
    "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR",
    // one or two characters
    "BANG", "BANG_EQUAL",
    "EQUAL", "EQUAL_EQUAL",
    "GREATER", "GREATER_EQUAL",
    "LESS", "LESS_EQUAL",

    // literals
    "IDENTIFIER", "STRING", "NUMBER",

    // keywords
    "AND", "CLASS", "ELSE", "FALSE", "FUN", "FOR", "IF", "NIL", "OR",
    "PRINT", "RETURN", "SUPER", "THIS", "TRUE", "VAR", "WHILE",

    // end of file
    "EF"
};


class Token{
    public:

    Token(TokenType type, std::string lexeme, std::string literal, int line);
    Token(TokenType type, std::string lexeme, double number_literal, int line);

    friend std::ostream& operator<<(std::ostream& os, const Token& obj) {
        os << toName[obj.type] << " " << obj.lexeme << " " << obj.literal << "\n";
        return os;
    }

    // variables
    TokenType type;
    std::string lexeme;
    std::string literal;
    double number_literal;
    int line;
};
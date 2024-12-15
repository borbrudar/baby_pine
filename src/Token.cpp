#include "Token.h"

Token::Token(TokenType type, std::string lexeme, std::string literal, int line){
        this->type = type;
        this->lexeme = lexeme;
        this->literal = literal;
        this->line = line;
}
Token::Token(TokenType type, std::string lexeme, double number_literal, int line) {
        this->type = type;
        this->lexeme = lexeme;
        this->number_literal = number_literal;
        this->line = line;
};
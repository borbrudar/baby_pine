#include "Scanner.h"
#include "Token.h"

Scanner::Scanner(std::string source){
    this->source = source;
}

bool Scanner::isAtEnd()
{
    return current >= source.size();
}

void Scanner::scanToken()
{
    char c = advance();
    switch(c) {
        case '(' : addToken(TokenType::LEFT_PAREN); break;
        case ')' : addToken(TokenType::RIGHT_PAREN); break;
        case '{' : addToken(TokenType::LEFT_BRACE); break;
        case '}' : addToken(TokenType::RIGHT_BRACE); break;
        case ',' : addToken(TokenType::COMMA); break;
        case '.' : addToken(TokenType::DOT); break;
        case '-' : addToken(TokenType::MINUS); break;
        case '+' : addToken(TokenType::PLUS); break;
        case ';' : addToken(TokenType::SEMICOLON); break;
        case '*' : addToken(TokenType::STAR); break;

        default:
            logger.error(line, "Unexpected character.");
            break;
    }

}

char Scanner::advance()
{
    return source[current++];
}

void Scanner::addToken(TokenType type)
{
    addToken(type, "");
}

void Scanner::addToken(TokenType type, std::string literal)
{
    std::string text = source.substr();
    tokens.push_back(Token(type,text,literal,line));
}

std::vector<Token> Scanner::scanTokens(){
    while(!isAtEnd()){
        start = current;
        scanToken();
    }
    tokens.push_back(Token(TokenType::EF, "","",line));

    return tokens;
}
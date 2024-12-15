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
        case '!' : 
            addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '=' :
            addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '<' :
            addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>' :
            addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;
        case '/' :
            if(match('/')){
                while(peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(TokenType::SLASH);
            }
            break;
        
        case ' ':
        case '\r':
        case '\t':
            break;
        case '\n':
            line++;
            break;
        

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

char Scanner::peek()
{
    if(isAtEnd()) return '\0';
    return source[current];  
}

void Scanner::addToken(TokenType type, std::string literal)
{
    std::string text = source.substr();
    tokens.push_back(Token(type,text,literal,line));
}

bool Scanner::bool match(char expected) {
    if (isAtEnd()) return false;
    if (source.charAt(current) != expected) return false;
    current++;
    return true;
}

std::vector<Token> Scanner::scanTokens(){
    while(!isAtEnd()){
        start = current;
        scanToken();
    }
    tokens.push_back(Token(TokenType::EF, "","",line));

    return tokens;
}
#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "Token.h"
#include "instruction.h"

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;

    Token currentToken();
    void eat(Token::Type type);

public:
    Parser(const std::vector<Token>& tokens);
    std::vector<Instruction> parseAssignment(const std::string& varName);
};

#endif // PARSER_H

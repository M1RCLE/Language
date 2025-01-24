#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "instruction.h"
#include "token.h"

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;

    Token currentToken();

    void eat(Token::Type type);

    std::any parseOperand();

    std::vector<Instruction> parseAssignment(const std::string &varName);

    std::vector<Instruction> parseArrayAssignment(const std::string &varName);

    std::vector<Instruction> parsePrintStatement();

    std::vector<Instruction> parseConditionalStatement();

    std::vector<Instruction> parseWhileStatement();

    Instruction parseReturnStatement();

    Instruction parseFunctionDeclaration();

public:
    Parser(const std::vector<Token> &tokens);

    std::vector<Instruction> parseSingle();

    std::vector<Instruction> parse();
};

#endif

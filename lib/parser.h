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

    void take(Token::Type type);

    std::any operandParser();

    std::vector<Instruction> assignmentParser(const std::string &varName);

    std::vector<Instruction> arrayAssignmentParser(const std::string &varName);

    std::vector<Instruction> printParser();

    std::vector<Instruction> conditionalStatementParser();

    std::vector<Instruction> whileStatementParser();

    Instruction returnStatementParser();

    Instruction functionDeclarationParser();


public:
    explicit Parser(const std::vector<Token> &tokens);

    std::vector<Instruction> parseSingle();

    std::vector<Instruction> parse();
};

#endif

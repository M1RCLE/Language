#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

#include "token.h"

class Lexer {
private:
    std::string input;
    size_t pos;
    char currentChar;

    void step();

    void ignoreWhitespaces();

    std::string collectNumber();

    std::string collectIdentifier();

public:
    explicit Lexer(const std::string &input);

    std::vector<Token> tokenize();
};

#endif  // LEXER_H

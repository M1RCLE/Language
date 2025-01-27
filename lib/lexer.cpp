#include "lexer.h"

#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string &input)
        : input(input), pos(0), currentChar(input[0]) {}

void Lexer::step() {
    pos++;
    if (pos < input.size()) {
        currentChar = input[pos];
    } else {
        currentChar = '\0';
    }
}

void Lexer::ignoreWhitespaces() {
    while (isspace(currentChar)) {
        step();
    }
}

std::string Lexer::collectNumber() {
    std::string number;
    while (isdigit(currentChar)) {
        number += currentChar;
        step();
    }
    return number;
}

std::string Lexer::collectIdentifier() {
    std::string identifier;
    while (isalnum(currentChar)) {
        identifier += currentChar;
        step();
    }
    return identifier;
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (currentChar != '\0') {
        if (currentChar == '=') {
            step();
            if (currentChar == '=') {
                tokens.emplace_back(Token::Type::EQUALS, "==");
                step();
            } else {
                tokens.emplace_back(Token::Type::EQUAL, "=");
            }
        } else if (currentChar == '+') {
            tokens.emplace_back(Token::Type::PLUS, "+");
            step();
        } else if (currentChar == '-') {
            tokens.emplace_back(Token::Type::MINUS, "-");
            step();
        } else if (currentChar == '*') {
            tokens.emplace_back(Token::Type::MULT, "*");
            step();
        } else if (currentChar == '%') {
            tokens.emplace_back(Token::Type::MOD, "%");
            step();
        } else if (currentChar == '<') {
            tokens.emplace_back(Token::Type::LESS, "<");
            step();
        } else if (currentChar == '>') {
            tokens.emplace_back(Token::Type::GREATER, ">");
            step();
        } else if (currentChar == ':') {
            tokens.emplace_back(Token::Type::COLON, ":");
            step();
        } else if (currentChar == ';') {
            tokens.emplace_back(Token::Type::SEMICOLON, ";");
            step();
        } else if (currentChar == '(') {
            if (!tokens.empty() && (tokens.back().type == Token::Type::IF ||
                                    tokens.back().type == Token::Type::WHILE ||
                                    tokens.back().type == Token::Type::FOR ||
                                    tokens.back().type == Token::Type::PRINT ||
                                    tokens.back().type == Token::Type::IDENTIFIER)) {
                tokens.emplace_back(Token::Type::LEFT_ELEMENT, "(");
            } else {
                throw std::runtime_error("Unexpected '(' - Use '{' for code blocks.");
            }
            step();
        } else if (currentChar == ')') {
            tokens.emplace_back(Token::Type::RIGHT_ELEMENT, ")");
            step();
        } else if (currentChar == '{') {
            tokens.emplace_back(Token::Type::BLOCK_OPEN, "{");
            step();
        } else if (currentChar == '}') {
            tokens.emplace_back(Token::Type::BLOCK_CLOSE, "}");
            step();
        } else if (currentChar == '[') {
            tokens.emplace_back(Token::Type::LEFT_BRACKET, "[");
            step();
        } else if (currentChar == ']') {
            tokens.emplace_back(Token::Type::RIGHT_BRACKET, "]");
            step();
        } else if (currentChar == ',') {
            tokens.emplace_back(Token::Type::COMMA, ",");
            step();
        } else if (currentChar == ',') {
            tokens.emplace_back(Token::Type::COMMA, ".");
            step();
        } else if (currentChar == '!') {
            step();
            if (currentChar == '=') {
                tokens.emplace_back(Token::Type::NOT_EQUALS, "!=");
                step();
            } else {
                throw std::runtime_error("Unexpected character: !");
            }
        } else if (isspace(currentChar)) {
            ignoreWhitespaces();
        } else if (isdigit(currentChar)) {
            tokens.emplace_back(Token::Type::NUMBER, collectNumber());
        } else if (isalpha(currentChar)) {
            std::string id = collectIdentifier();
            if (id == "var") {
                tokens.emplace_back(Token::Type::VAR, id);
            } else if (id == "print") {
                tokens.emplace_back(Token::Type::PRINT, id);
            } else if (id == "if") {
                tokens.emplace_back(Token::Type::IF, id);
            } else if (id == "while") {
                tokens.emplace_back(Token::Type::WHILE, id);
            } else if (id == "for") {
                tokens.emplace_back(Token::Type::FOR, id);
            } else if (id == "def") {
                tokens.emplace_back(Token::Type::DEF, id);
            } else if (id == "return") {
                tokens.emplace_back(Token::Type::RETURN, id);
            } else if (id == "new") {
                tokens.emplace_back(Token::Type::NEW, id);
            } else {
                tokens.emplace_back(Token::Type::IDENTIFIER, id);
            }
        } else {
            throw std::runtime_error("Unexpected character: " + std::string(1, currentChar));
        }

    }
    return tokens;
}

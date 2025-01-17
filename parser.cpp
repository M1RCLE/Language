#include "parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

Token Parser::currentToken() {
    return tokens[pos];
}

void Parser::eat(Token::Type type) {
    if (currentToken().type == type) {
        pos++;
    } else {
        throw std::runtime_error("Unexpected token: " + std::to_string(static_cast<int>(currentToken().type)));
    }
}

std::vector<Instruction> Parser::parseAssignment(const std::string& varName) {
    std::vector<Instruction> instructions;
    eat(Token::Type::EQUAL);

    if (currentToken().type == Token::Type::NEW) {
        eat(Token::Type::NEW);
        eat(Token::Type::LEFT_BRACKET);
        std::string amount = currentToken().value;
        eat(Token::Type::NUMBER);
        eat(Token::Type::RIGHT_BRACKET);
        instructions.push_back(Instruction(Instruction::OpCode::NEW, varName, amount));
    } else if (currentToken().type == Token::Type::NUMBER || currentToken().type == Token::Type::IDENTIFIER) {
        std::string operand1 = currentToken().value;
        eat(currentToken().type);
        if (currentToken().type == Token::Type::PLUS) {
            eat(Token::Type::PLUS);
            std::string operand2 = currentToken().value;
            eat(Token::Type::NUMBER);
            instructions.push_back(Instruction(Instruction::OpCode::ADD, varName, operand1, operand2));
        }
    }
    eat(Token::Type::SEMICOLON);
    return instructions;
}

#include "parser.h"

#include <stdexcept>

Parser::Parser(const std::vector<Token> &tokens) : tokens(tokens), pos(0) {}

Token Parser::currentToken() { return tokens[pos]; }

void Parser::take(Token::Type type) {
    if (currentToken().type == type) {
        pos++;
    } else {
        throw std::runtime_error(
                "Unexpected token: " +
                std::to_string(static_cast<int>(currentToken().type)));
    }
}

std::any Parser::operandParser() {
    std::any operand = currentToken().value;
    take(currentToken().type);
    return operand;
}

std::vector<Instruction> Parser::assignmentParser(const std::string &varName) {
    std::vector<Instruction> instructions;
    take(Token::Type::EQUAL);

    if (currentToken().type == Token::Type::NEW) {
        take(Token::Type::NEW);
        take(Token::Type::LEFT_BRACKET);
        std::any amount = currentToken().value;
        take(Token::Type::NUMBER);
        take(Token::Type::RIGHT_BRACKET);
        instructions.emplace_back(Instruction::OperationCode::NEW, varName, amount);
    } else if (currentToken().type == Token::Type::NUMBER ||
               currentToken().type == Token::Type::IDENTIFIER) {
        std::any reg1 = operandParser();

        if (currentToken().type == Token::Type::LEFT_BRACKET) {
            take(Token::Type::LEFT_BRACKET);
            std::any index = currentToken().value;
            take(currentToken().type);
            take(Token::Type::RIGHT_BRACKET);
            instructions.emplace_back(Instruction::OperationCode::ARRAY_VARIABLE_STORAGE,
                                               std::any_cast<std::string>(reg1),
                                               index, varName);
        } else if (currentToken().type == Token::Type::PLUS) {
            take(Token::Type::PLUS);
            std::any reg2 = operandParser();
            instructions.emplace_back(
                    Instruction::OperationCode::ADD, varName, reg1, reg2);
        } else if (currentToken().type == Token::Type::MINUS) {
            take(Token::Type::MINUS);
            std::any reg2 = operandParser();
            instructions.emplace_back(
                    Instruction::OperationCode::SUB, varName, reg1, reg2);
        } else if (currentToken().type == Token::Type::MULT) {
            take(Token::Type::MULT);
            std::any reg2 = operandParser();
            instructions.emplace_back(
                    Instruction::OperationCode::MUL, varName, reg1, reg2);
        } else if (currentToken().type == Token::Type::MOD) {
            take(Token::Type::MOD);
            std::any reg2 = operandParser();
            instructions.emplace_back(
                    Instruction::OperationCode::MOD, varName, reg1, reg2);
        } else if (currentToken().type == Token::Type::LESS) {
            take(Token::Type::LESS);
            std::any reg2 = operandParser();
            instructions.emplace_back(
                    Instruction::OperationCode::LESS, varName, reg1, reg2);
        } else if (currentToken().type == Token::Type::GREATER) {
            take(Token::Type::GREATER);
            std::any reg2 = operandParser();
            instructions.emplace_back(Instruction::OperationCode::GREATER, varName,
                                      reg1, reg2);
        } else if (currentToken().type == Token::Type::EQUALS) {
            take(Token::Type::EQUALS);
            std::any reg2 = operandParser();
            instructions.emplace_back(Instruction::OperationCode::EQUALS, varName,
                                      reg1, reg2);
        } else if (currentToken().type == Token::Type::NOT_EQUALS) {
            take(Token::Type::NOT_EQUALS);
            std::any reg2 = operandParser();
            instructions.emplace_back(Instruction::OperationCode::NOT_EQUALS,
                                      varName, reg1, reg2);
        } else if (currentToken().type == Token::Type::LEFT_ELEMENT) {
            take(Token::Type::LEFT_ELEMENT);
            auto functionName = std::any_cast<std::string>(reg1);
            std::vector<std::string> arguments;
            while (currentToken().type != Token::Type::RIGHT_ELEMENT) {
                if (currentToken().type == Token::Type::NUMBER ||
                    currentToken().type == Token::Type::IDENTIFIER) {
                    arguments.push_back(currentToken().value);
                    take(currentToken().type);
                } else if (currentToken().type == Token::Type::COMMA) {
                    take(Token::Type::COMMA);
                }
            }
            take(Token::Type::RIGHT_ELEMENT);
            instructions.emplace_back(Instruction(Instruction::OperationCode::CALL, functionName, arguments, varName));
        } else {
            instructions.emplace_back(
                    Instruction::OperationCode::SAVE, varName, reg1);
        }
    }
    take(Token::Type::SEMICOLON);
    return instructions;
}

std::vector<Instruction> Parser::arrayAssignmentParser(
        const std::string &varName) {
    std::vector<Instruction> instructions;
    take(Token::Type::LEFT_BRACKET);
    std::any index = currentToken().value;
    take(currentToken().type);
    take(Token::Type::RIGHT_BRACKET);
    take(Token::Type::EQUAL);
    std::any value = currentToken().value;
    take(currentToken().type);
    instructions.emplace_back(Instruction::OperationCode::WRITE_INDEX, varName, index, value);
    take(Token::Type::SEMICOLON);
    return instructions;
}

std::vector<Instruction> Parser::printParser() {
    std::vector<Instruction> instructions;
    take(Token::Type::PRINT);
    take(Token::Type::LEFT_ELEMENT);
    std::string varName = currentToken().value;
    take(Token::Type::IDENTIFIER);
    if (currentToken().type == Token::Type::LEFT_ELEMENT) {
        take(Token::Type::LEFT_ELEMENT);
        std::string index = currentToken().value;
        take(currentToken().type);
        take(Token::Type::RIGHT_ELEMENT);
        take(Token::Type::RIGHT_ELEMENT);
        take(Token::Type::SEMICOLON);
        instructions.emplace_back(Instruction::OperationCode::READ_INDEX, varName, index);
        return instructions;
    }

    take(Token::Type::RIGHT_ELEMENT);
    take(Token::Type::SEMICOLON);
    instructions.emplace_back(Instruction::OperationCode::PRINT, varName);
    return instructions;
}

std::vector<Instruction> Parser::conditionalStatementParser() {
    std::vector<Instruction> instructions;
    take(Token::Type::IF);
    take(Token::Type::LEFT_ELEMENT);
    std::any conditionOperand1 = currentToken().value;
    take(currentToken().type);
    Token::Type comparisonType = currentToken().type;
    take(comparisonType);
    std::any conditionOperand2 = currentToken().value;
    take(currentToken().type);
    take(Token::Type::RIGHT_ELEMENT);

    std::vector<Instruction> blockInstructions;
    take(Token::Type::BLOCK_OPEN);
    while (currentToken().type != Token::Type::BLOCK_CLOSE) {
        auto single = parseSingle();
        blockInstructions.insert(blockInstructions.end(), single.begin(),
                                 single.end());
    }
    take(Token::Type::BLOCK_CLOSE);

    Instruction::OperationCode comparisonOpCode;
    switch (comparisonType) {
        case Token::Type::LESS:
            comparisonOpCode = Instruction::OperationCode::LESS;
            break;
        case Token::Type::GREATER:
            comparisonOpCode = Instruction::OperationCode::GREATER;
            break;
        case Token::Type::EQUALS:
            comparisonOpCode = Instruction::OperationCode::EQUALS;
            break;
        case Token::Type::NOT_EQUALS:
            comparisonOpCode = Instruction::OperationCode::NOT_EQUALS;
            break;
        case Token::Type::RETURN:
            comparisonOpCode = Instruction::OperationCode::RETURN;
            break;
        default:
            throw std::runtime_error("Unsupported comparison operator");
    }

    instructions.emplace_back(
            Instruction::OperationCode::IF, std::any_cast<std::string>(conditionOperand1),
            comparisonOpCode, conditionOperand2, blockInstructions);
    return instructions;
}

std::vector<Instruction> Parser::whileStatementParser() {
    std::vector<Instruction> instructions;
    take(Token::Type::WHILE);
    take(Token::Type::LEFT_ELEMENT);
    std::any conditionOperand1 = currentToken().value;
    take(currentToken().type);
    Token::Type comparisonType = currentToken().type;
    take(comparisonType);
    std::any conditionOperand2 = currentToken().value;
    take(currentToken().type);
    take(Token::Type::RIGHT_ELEMENT);

    std::vector<Instruction> blockInstructions;
    take(Token::Type::BLOCK_OPEN);
    while (currentToken().type != Token::Type::BLOCK_CLOSE) {
        auto single = parseSingle();
        blockInstructions.insert(blockInstructions.end(), single.begin(),
                                 single.end());
    }
    take(Token::Type::BLOCK_CLOSE);

    Instruction::OperationCode comparisonOpCode;
    switch (comparisonType) {
        case Token::Type::LESS:
            comparisonOpCode = Instruction::OperationCode::LESS;
            break;
        case Token::Type::GREATER:
            comparisonOpCode = Instruction::OperationCode::GREATER;
            break;
        case Token::Type::EQUALS:
            comparisonOpCode = Instruction::OperationCode::EQUALS;
            break;
        case Token::Type::NOT_EQUALS:
            comparisonOpCode = Instruction::OperationCode::NOT_EQUALS;
            break;
        case Token::Type::RETURN:
            comparisonOpCode = Instruction::OperationCode::RETURN;
            break;
        default:
            throw std::runtime_error("Unsupported comparison operator");
    }


    instructions.emplace_back(Instruction(
        Instruction::OperationCode::WHILE, std::any_cast<std::string>(conditionOperand1),
        comparisonOpCode, conditionOperand2, blockInstructions));

    return instructions;
}

std::vector<Instruction> Parser::forStatementParser() {
    std::vector<Instruction> instructions;
    take(Token::Type::FOR);
    take(Token::Type::LEFT_ELEMENT);
    std::string variableName = currentToken().value;
    take(Token::Type::IDENTIFIER);
    take(Token::Type::COLON);
    std::any initializationValue = currentToken().value;
    take(currentToken().type);
    take(Token::Type::COLON);
    std::any limitValue = currentToken().value;
    take(currentToken().type);
    take(Token::Type::RIGHT_ELEMENT);

    std::vector<Instruction> blockInstructions;
    take(Token::Type::BLOCK_OPEN);
    while (currentToken().type != Token::Type::BLOCK_CLOSE) {
        auto single = parseSingle();
        blockInstructions.insert(blockInstructions.end(), single.begin(),
                                 single.end());
    }
    take(Token::Type::BLOCK_CLOSE);
    Instruction forInstr =
        Instruction(Instruction::OperationCode::FOR, variableName,
                    initializationValue, limitValue, blockInstructions);

    instructions.push_back(forInstr);

    return instructions;
}

Instruction Parser::returnStatementParser() {
    take(Token::Type::RETURN);

    std::string returnValue = currentToken().value;
    take(currentToken().type);

    if (currentToken().type == Token::Type::CALL_FUN_OPEN) {
        take(Token::Type::CALL_FUN_OPEN);
        std::vector<std::any> arguments;

        while (currentToken().type != Token::Type::CALL_FUN_CLOSE) {
            if (currentToken().type == Token::Type::NUMBER ||
                currentToken().type == Token::Type::IDENTIFIER) {
                arguments.push_back(currentToken().value);
                take(currentToken().type);
            } else if (currentToken().type == Token::Type::COMMA) {
                take(Token::Type::COMMA);
            }
        }

        take(Token::Type::CALL_FUN_CLOSE);        
        take(Token::Type::SEMICOLON);
        return Instruction(Instruction::OperationCode::RETURN, nullptr, Instruction(Instruction::OperationCode::CALL, returnValue, arguments, nullptr));
    }
    take(Token::Type::SEMICOLON);
    return Instruction(Instruction::OperationCode::RETURN, returnValue);
}

Instruction Parser::functionDeclarationParser() {
    std::vector<Instruction> instructions;
    take(Token::Type::DEF);
    std::string functionName = currentToken().value;
    take(Token::Type::IDENTIFIER);

    take(Token::Type::LEFT_ELEMENT);
    std::vector<std::string> parameters;
    while (currentToken().type != Token::Type::RIGHT_ELEMENT) {
        take(Token::Type::VAR);
        parameters.push_back(currentToken().value);
        take(Token::Type::IDENTIFIER);
        if (currentToken().type == Token::Type::COMMA) {
            take(Token::Type::COMMA);
        }
    }
    take(Token::Type::RIGHT_ELEMENT);
    take(Token::Type::BLOCK_OPEN);

    while (currentToken().type != Token::Type::BLOCK_CLOSE) {
        if (currentToken().type == Token::Type::VAR) {
            take(Token::Type::VAR);
            std::string varName = currentToken().value;
            take(Token::Type::IDENTIFIER);

            if (currentToken().type == Token::Type::LEFT_BRACKET) {
                auto assignment = arrayAssignmentParser(varName);
                instructions.insert(instructions.end(), assignment.begin(),
                                    assignment.end());
            } else {
                auto assignment = assignmentParser(varName);
                instructions.insert(instructions.end(), assignment.begin(),
                                    assignment.end());
            }
        } else if (currentToken().type == Token::Type::PRINT) {
            auto printStmt = printParser();
            instructions.insert(instructions.end(), printStmt.begin(),
                                printStmt.end());
        } else if (currentToken().type == Token::Type::IF) {
            auto conditionalStmt = conditionalStatementParser();
            instructions.insert(instructions.end(), conditionalStmt.begin(),
                                conditionalStmt.end());
        } else if (currentToken().type == Token::Type::WHILE) {
            auto loopStmt = whileStatementParser();
            instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
        } else if (currentToken().type == Token::Type::FOR) {
            auto loopStmt = forStatementParser();
            instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
        } else if (currentToken().type == Token::Type::RETURN) {
            instructions.push_back(returnStatementParser());
        } else {
            throw std::runtime_error("Unknown statement");
        }
    }
    take(Token::Type::BLOCK_CLOSE);

    return Instruction::FunctionInstruction(functionName, parameters,
                                            instructions);
}

std::vector<Instruction> Parser::parseSingle() {
    std::vector<Instruction> instructions;
    if (currentToken().type == Token::Type::VAR) {
        take(Token::Type::VAR);
        std::string varName = currentToken().value;
        take(Token::Type::IDENTIFIER);

        if (currentToken().type == Token::Type::LEFT_BRACKET) {
            auto assignment = arrayAssignmentParser(varName);
            instructions.insert(instructions.end(), assignment.begin(),
                                assignment.end());
        } else {
            auto assignment = assignmentParser(varName);
            instructions.insert(instructions.end(), assignment.begin(),
                                assignment.end());
        }
    } else if (currentToken().type == Token::Type::PRINT) {
        auto printStmt = printParser();
        instructions.insert(instructions.end(), printStmt.begin(), printStmt.end());
    } else if (currentToken().type == Token::Type::DEF) {
        instructions.push_back(functionDeclarationParser());
    } else if (currentToken().type == Token::Type::RETURN) {
        instructions.push_back(returnStatementParser());
    } else if (currentToken().type == Token::Type::IF) {
        auto conditionalStmt = conditionalStatementParser();
        instructions.insert(instructions.end(), conditionalStmt.begin(),
                            conditionalStmt.end());
    } else if (currentToken().type == Token::Type::WHILE) {
        auto loopStmt = whileStatementParser();
        instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
    } else if (currentToken().type == Token::Type::FOR) {
        auto loopStmt = forStatementParser();
        instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
    } else {
        throw std::runtime_error("Unknown statement");
    }
    return instructions;
}

std::vector<Instruction> Parser::parse() {
    std::vector<Instruction> instructions;
    while (pos < tokens.size()) {
        if (currentToken().type == Token::Type::DEF) {
            Instruction instruction = functionDeclarationParser();
            instructions.push_back(instruction);
        } else if (currentToken().type == Token::Type::VAR) {
            take(Token::Type::VAR);
            std::string varName = currentToken().value;
            take(Token::Type::IDENTIFIER);

            if (currentToken().type == Token::Type::LEFT_BRACKET) {
                auto assignment = arrayAssignmentParser(varName);
                instructions.insert(instructions.end(), assignment.begin(),
                                    assignment.end());
            } else {
                auto assignment = assignmentParser(varName);
                instructions.insert(instructions.end(), assignment.begin(),
                                    assignment.end());
            }
        } else if (currentToken().type == Token::Type::PRINT) {
            auto printStmt = printParser();
            instructions.insert(instructions.end(), printStmt.begin(),
                                printStmt.end());
        } else if (currentToken().type == Token::Type::IF) {
            auto conditionalStmt = conditionalStatementParser();
            instructions.insert(instructions.end(), conditionalStmt.begin(),
                                conditionalStmt.end());
        } else if (currentToken().type == Token::Type::RETURN) {
            instructions.push_back(returnStatementParser());
        } else if (currentToken().type == Token::Type::WHILE) {
            auto loopStmt = whileStatementParser();
            instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
        } else if (currentToken().type == Token::Type::FOR) {
            auto loopStmt = forStatementParser();
            instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
        } else {
            throw std::runtime_error("Unknown statement");
        }
    }
    return instructions;
}
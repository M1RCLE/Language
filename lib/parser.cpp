#include "parser.h"

#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), pos(0) {}

Token Parser::currentToken() { return tokens[pos]; }

void Parser::eat(Token::Type type) {
  if (currentToken().type == type) {
    pos++;
  } else {
    throw std::runtime_error(
        "Unexpected token: " +
        std::to_string(static_cast<int>(currentToken().type)));
  }
}

std::any Parser::parseOperand() {
  std::any operand = currentToken().value;
  eat(currentToken().type);
  return operand;
}

std::vector<Instruction> Parser::parseAssignment(const std::string& varName) {
  std::vector<Instruction> instructions;
  eat(Token::Type::EQUAL);

  if (currentToken().type == Token::Type::NEW) {
    eat(Token::Type::NEW);
    eat(Token::Type::LEFT_BRACKET);
    std::any amount = currentToken().value;
    eat(Token::Type::NUMBER);
    eat(Token::Type::RIGHT_BRACKET);
    instructions.push_back(
        Instruction(Instruction::OpCode::NEW, varName, amount));
  } else if (currentToken().type == Token::Type::NUMBER ||
             currentToken().type == Token::Type::IDENTIFIER) {
    std::any operand1 = parseOperand();

    if (currentToken().type == Token::Type::LEFT_BRACKET) {
      eat(Token::Type::LEFT_BRACKET);
      std::any index = currentToken().value;
      eat(currentToken().type);
      eat(Token::Type::RIGHT_BRACKET);
      instructions.push_back(Instruction(Instruction::OpCode::STORE_ARRAY_VAR,
                                         std::any_cast<std::string>(operand1),
                                         index, varName));
    } else if (currentToken().type == Token::Type::PLUS) {
      eat(Token::Type::PLUS);
      std::any operand2 = parseOperand();
      instructions.push_back(
          Instruction(Instruction::OpCode::ADD, varName, operand1, operand2));
    } else if (currentToken().type == Token::Type::MINUS) {
      eat(Token::Type::MINUS);
      std::any operand2 = parseOperand();
      instructions.push_back(
          Instruction(Instruction::OpCode::SUB, varName, operand1, operand2));
    } else if (currentToken().type == Token::Type::STAR) {
      eat(Token::Type::STAR);
      std::any operand2 = parseOperand();
      instructions.push_back(
          Instruction(Instruction::OpCode::MUL, varName, operand1, operand2));
    } else if (currentToken().type == Token::Type::MOD) {
      eat(Token::Type::MOD);
      std::any operand2 = parseOperand();
      instructions.push_back(
          Instruction(Instruction::OpCode::MOD, varName, operand1, operand2));
    } else if (currentToken().type == Token::Type::LESS) {
      eat(Token::Type::LESS);
      std::any operand2 = parseOperand();
      instructions.push_back(
          Instruction(Instruction::OpCode::LESS, varName, operand1, operand2));
    } else if (currentToken().type == Token::Type::GREATER) {
      eat(Token::Type::GREATER);
      std::any operand2 = parseOperand();
      instructions.push_back(Instruction(Instruction::OpCode::GREATER, varName,
                                         operand1, operand2));
    } else if (currentToken().type == Token::Type::EQUALS) {
      eat(Token::Type::EQUALS);
      std::any operand2 = parseOperand();
      instructions.push_back(Instruction(Instruction::OpCode::EQUALS, varName,
                                         operand1, operand2));
    } else if (currentToken().type == Token::Type::NOT_EQUALS) {
      eat(Token::Type::NOT_EQUALS);
      std::any operand2 = parseOperand();
      instructions.push_back(Instruction(Instruction::OpCode::NOT_EQUALS,
                                         varName, operand1, operand2));
    } else if (currentToken().type == Token::Type::CALL_FUN_OPEN) {
      eat(Token::Type::CALL_FUN_OPEN);
      std::string functionName = std::any_cast<std::string>(operand1);
      std::vector<std::string> arguments;
      while (currentToken().type != Token::Type::CALL_FUN_CLOSE) {
        if (currentToken().type == Token::Type::NUMBER ||
            currentToken().type == Token::Type::IDENTIFIER) {
          arguments.push_back(currentToken().value);
          eat(currentToken().type);
        } else if (currentToken().type == Token::Type::COMMA) {
          eat(Token::Type::COMMA);
        }
      }
      eat(Token::Type::CALL_FUN_CLOSE);
      instructions.push_back(Instruction(Instruction::OpCode::CALL,
                                         functionName, arguments, varName));
    } else {
      instructions.push_back(
          Instruction(Instruction::OpCode::STORE, varName, operand1));
    }
  }
  eat(Token::Type::SEMICOLON);
  return instructions;
}

std::vector<Instruction> Parser::parseArrayAssignment(
    const std::string& varName) {
  std::vector<Instruction> instructions;
  eat(Token::Type::LEFT_BRACKET);
  std::any index = currentToken().value;
  eat(currentToken().type);
  eat(Token::Type::RIGHT_BRACKET);
  eat(Token::Type::EQUAL);
  std::any value = currentToken().value;
  eat(currentToken().type);
  instructions.push_back(
      Instruction(Instruction::OpCode::WRITE_INDEX, varName, index, value));
  eat(Token::Type::SEMICOLON);
  return instructions;
}

std::vector<Instruction> Parser::parsePrintStatement() {
  std::vector<Instruction> instructions;
  eat(Token::Type::PRINT);
  eat(Token::Type::LEFT_BRACKET);
  std::string varName = currentToken().value;
  eat(Token::Type::IDENTIFIER);
  if (currentToken().type == Token::Type::LEFT_BRACKET) {
    eat(Token::Type::LEFT_BRACKET);
    std::string index = currentToken().value;
    eat(currentToken().type);
    eat(Token::Type::RIGHT_BRACKET);
    eat(Token::Type::RIGHT_BRACKET);
    eat(Token::Type::SEMICOLON);
    instructions.push_back(
        Instruction(Instruction::OpCode::READ_INDEX, varName, index));
    return instructions;
  }

  eat(Token::Type::RIGHT_BRACKET);
  eat(Token::Type::SEMICOLON);
  instructions.push_back(Instruction(Instruction::OpCode::PRINT, varName));
  return instructions;
}

std::vector<Instruction> Parser::parseConditionalStatement() {
  std::vector<Instruction> instructions;
  eat(Token::Type::IF);
  eat(Token::Type::LEFT_BRACKET);
  std::any conditionOperand1 = currentToken().value;
  eat(currentToken().type);
  Token::Type comparisonType = currentToken().type;
  eat(comparisonType);
  std::any conditionOperand2 = currentToken().value;
  eat(currentToken().type);
  eat(Token::Type::RIGHT_BRACKET);

  std::vector<Instruction> blockInstructions;
  eat(Token::Type::LEFT_BRACKET);
  while (currentToken().type != Token::Type::RIGHT_BRACKET) {
    auto single = parseSingle();
    blockInstructions.insert(blockInstructions.end(), single.begin(),
                             single.end());
  }
  eat(Token::Type::RIGHT_BRACKET);

  Instruction::OpCode comparisonOpCode;
  switch (comparisonType) {
    case Token::Type::LESS:
      comparisonOpCode = Instruction::OpCode::LESS;
      break;
    case Token::Type::GREATER:
      comparisonOpCode = Instruction::OpCode::GREATER;
      break;
    case Token::Type::EQUALS:
      comparisonOpCode = Instruction::OpCode::EQUALS;
      break;
    case Token::Type::NOT_EQUALS:
      comparisonOpCode = Instruction::OpCode::NOT_EQUALS;
      break;
    case Token::Type::RETURN:
      comparisonOpCode = Instruction::OpCode::RETURN;
      break;
    default:
      throw std::runtime_error("Unsupported comparison operator");
      break;
  }

  instructions.push_back(Instruction(
      Instruction::OpCode::IF, std::any_cast<std::string>(conditionOperand1),
      comparisonOpCode, conditionOperand2, blockInstructions));
  return instructions;
}

std::vector<Instruction> Parser::parseLoopStatement() {
  std::vector<Instruction> instructions;
  eat(Token::Type::WHILE);
  eat(Token::Type::LEFT_BRACKET);
  std::any conditionOperand1 = currentToken().value;
  eat(currentToken().type);
  Token::Type comparisonType = currentToken().type;
  eat(comparisonType);
  std::any conditionOperand2 = currentToken().value;
  eat(currentToken().type);
  eat(Token::Type::RIGHT_BRACKET);

  std::vector<Instruction> blockInstructions;
  eat(Token::Type::LEFT_BRACKET);
  while (currentToken().type != Token::Type::RIGHT_BRACKET) {
    auto single = parseSingle();
    blockInstructions.insert(blockInstructions.end(), single.begin(),
                             single.end());
  }
  eat(Token::Type::RIGHT_BRACKET);

  Instruction::OpCode comparisonOpCode;
  switch (comparisonType) {
    case Token::Type::LESS:
      comparisonOpCode = Instruction::OpCode::LESS;
      break;
    case Token::Type::GREATER:
      comparisonOpCode = Instruction::OpCode::GREATER;
      break;
    case Token::Type::EQUALS:
      comparisonOpCode = Instruction::OpCode::EQUALS;
      break;
    case Token::Type::NOT_EQUALS:
      comparisonOpCode = Instruction::OpCode::NOT_EQUALS;
      break;
    case Token::Type::RETURN:
      comparisonOpCode = Instruction::OpCode::RETURN;
      break;
    default:
      throw std::runtime_error("Unsupported comparison operator");
  }

  instructions.push_back(Instruction(
      Instruction::OpCode::WHILE, std::any_cast<std::string>(conditionOperand1),
      comparisonOpCode, conditionOperand2, blockInstructions));
  return instructions;
}

Instruction Parser::parseReturnStatement() {
  eat(Token::Type::RETURN);

  std::string returnValue = currentToken().value;
  eat(currentToken().type);

  if (currentToken().type == Token::Type::CALL_FUN_OPEN) {
    eat(Token::Type::CALL_FUN_OPEN);
    std::vector<std::any> arguments;

    while (currentToken().type != Token::Type::CALL_FUN_CLOSE) {
      if (currentToken().type == Token::Type::NUMBER ||
          currentToken().type == Token::Type::IDENTIFIER) {
        arguments.push_back(currentToken().value);
        eat(currentToken().type);
      } else if (currentToken().type == Token::Type::COMMA) {
        eat(Token::Type::COMMA);
      }
    }

    eat(Token::Type::CALL_FUN_CLOSE);

    Instruction instruction =
        Instruction(Instruction::OpCode::CALL, returnValue, arguments, nullptr);
    eat(Token::Type::SEMICOLON);
    return Instruction(Instruction::OpCode::RETURN, nullptr, instruction);
  }
  eat(Token::Type::SEMICOLON);
  return Instruction(Instruction::OpCode::RETURN, returnValue);
}

Instruction Parser::parseFunctionDeclaration() {
  std::vector<Instruction> instructions;
  eat(Token::Type::FUNC);
  std::string functionName = currentToken().value;
  eat(Token::Type::IDENTIFIER);

  eat(Token::Type::LEFT_BRACKET);
  std::vector<std::string> parameters;
  while (currentToken().type != Token::Type::RIGHT_BRACKET) {
    eat(Token::Type::LET);
    parameters.push_back(currentToken().value);
    eat(Token::Type::IDENTIFIER);
    if (currentToken().type == Token::Type::COMMA) {
      eat(Token::Type::COMMA);
    }
  }
  eat(Token::Type::RIGHT_BRACKET);

  while (currentToken().type != Token::Type::RETURN) {
    if (currentToken().type == Token::Type::LET) {
      eat(Token::Type::LET);
      std::string varName = currentToken().value;
      eat(Token::Type::IDENTIFIER);

      if (currentToken().type == Token::Type::LEFT_BRACKET) {
        auto assignment = parseArrayAssignment(varName);
        instructions.insert(instructions.end(), assignment.begin(),
                            assignment.end());
      } else {
        auto assignment = parseAssignment(varName);
        instructions.insert(instructions.end(), assignment.begin(),
                            assignment.end());
      }
    } else if (currentToken().type == Token::Type::PRINT) {
      auto printStmt = parsePrintStatement();
      instructions.insert(instructions.end(), printStmt.begin(),
                          printStmt.end());
    } else if (currentToken().type == Token::Type::IF) {
      auto conditionalStmt = parseConditionalStatement();
      instructions.insert(instructions.end(), conditionalStmt.begin(),
                          conditionalStmt.end());
    } else if (currentToken().type == Token::Type::WHILE) {
      auto loopStmt = parseLoopStatement();
      instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
    } else {
      throw std::runtime_error("Unknown statement");
    }
  }
  instructions.push_back(parseReturnStatement());

  return Instruction::FunctionInstruction(functionName, parameters,
                                          instructions);
}

std::vector<Instruction> Parser::parseSingle() {
  std::vector<Instruction> instructions;
  if (currentToken().type == Token::Type::LET) {
    eat(Token::Type::LET);
    std::string varName = currentToken().value;
    eat(Token::Type::IDENTIFIER);

    if (currentToken().type == Token::Type::LEFT_BRACKET) {
      auto assignment = parseArrayAssignment(varName);
      instructions.insert(instructions.end(), assignment.begin(),
                          assignment.end());
    } else {
      auto assignment = parseAssignment(varName);
      instructions.insert(instructions.end(), assignment.begin(),
                          assignment.end());
    }
  } else if (currentToken().type == Token::Type::PRINT) {
    auto printStmt = parsePrintStatement();
    instructions.insert(instructions.end(), printStmt.begin(), printStmt.end());
  } else if (currentToken().type == Token::Type::FUNC) {
    instructions.push_back(parseFunctionDeclaration());
  } else if (currentToken().type == Token::Type::RETURN) {
    instructions.push_back(parseReturnStatement());
  } else if (currentToken().type == Token::Type::IF) {
    auto conditionalStmt = parseConditionalStatement();
    instructions.insert(instructions.end(), conditionalStmt.begin(),
                        conditionalStmt.end());
  } else if (currentToken().type == Token::Type::WHILE) {
    auto loopStmt = parseLoopStatement();
    instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
  } else {
    throw std::runtime_error("Unknown statement");
  }
  return instructions;
}

std::vector<Instruction> Parser::parse() {
  std::vector<Instruction> instructions;
  while (pos < tokens.size()) {
    if (currentToken().type == Token::Type::FUNC) {
      Instruction instruction = parseFunctionDeclaration();
      instructions.push_back(instruction);
    } else if (currentToken().type == Token::Type::LET) {
      eat(Token::Type::LET);
      std::string varName = currentToken().value;
      eat(Token::Type::IDENTIFIER);

      if (currentToken().type == Token::Type::LEFT_BRACKET) {
        auto assignment = parseArrayAssignment(varName);
        instructions.insert(instructions.end(), assignment.begin(),
                            assignment.end());
      } else {
        auto assignment = parseAssignment(varName);
        instructions.insert(instructions.end(), assignment.begin(),
                            assignment.end());
      }
    } else if (currentToken().type == Token::Type::PRINT) {
      auto printStmt = parsePrintStatement();
      instructions.insert(instructions.end(), printStmt.begin(),
                          printStmt.end());
    } else if (currentToken().type == Token::Type::IF) {
      auto conditionalStmt = parseConditionalStatement();
      instructions.insert(instructions.end(), conditionalStmt.begin(),
                          conditionalStmt.end());
    } else if (currentToken().type == Token::Type::RETURN) {
      instructions.push_back(parseReturnStatement());
    } else if (currentToken().type == Token::Type::WHILE) {
      auto loopStmt = parseLoopStatement();
      instructions.insert(instructions.end(), loopStmt.begin(), loopStmt.end());
    } else {
      throw std::runtime_error("Unknown statement");
    }
  }
  return instructions;
}
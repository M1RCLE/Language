#include "lexer.h"

#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& input)
    : input(input), pos(0), currentChar(input[0]) {}

void Lexer::advance() {
  pos++;
  if (pos < input.size()) {
    currentChar = input[pos];
  } else {
    currentChar = '\0';
  }
}

void Lexer::skipWhitespace() {
  while (isspace(currentChar)) {
    advance();
  }
}

std::string Lexer::collectNumber() {
  std::string number;
  while (isdigit(currentChar)) {
    number += currentChar;
    advance();
  }
  return number;
}

std::string Lexer::collectIdentifier() {
  std::string identifier;
  while (isalnum(currentChar)) {
    identifier += currentChar;
    advance();
  }
  return identifier;
}

std::vector<Token> Lexer::tokenize() {
  std::vector<Token> tokens;
  while (currentChar != '\0') {
    if (isspace(currentChar)) {
      skipWhitespace();
    } else if (isdigit(currentChar)) {
      tokens.push_back(Token(Token::Type::NUMBER, collectNumber()));
    } else if (isalpha(currentChar)) {
      std::string id = collectIdentifier();
      if (id == "let") {
        tokens.push_back(Token(Token::Type::LET, id));
      } else if (id == "print") {
        tokens.push_back(Token(Token::Type::PRINT, id));
      } else if (id == "if") {
        tokens.push_back(Token(Token::Type::IF, id));
      } else if (id == "while") {
        tokens.push_back(Token(Token::Type::WHILE, id));
      } else if (id == "func") {
        tokens.push_back(Token(Token::Type::FUNC, id));
      } else if (id == "return") {
        tokens.push_back(Token(Token::Type::RETURN, id));
      } else if (id == "new") {
        tokens.push_back(Token(Token::Type::NEW, id));
      } else {
        tokens.push_back(Token(Token::Type::IDENTIFIER, id));
      }
    } else if (currentChar == '=') {
      advance();
      if (currentChar == '=') {
        tokens.push_back(Token(Token::Type::EQUALS, "=="));
        advance();
      } else {
        tokens.push_back(Token(Token::Type::EQUAL, "="));
      }
    } else if (currentChar == '+') {
      tokens.push_back(Token(Token::Type::PLUS, "+"));
      advance();
    } else if (currentChar == '-') {
      tokens.push_back(Token(Token::Type::MINUS, "-"));
      advance();
    } else if (currentChar == '*') {
      tokens.push_back(Token(Token::Type::STAR, "*"));
      advance();
    } else if (currentChar == '%') {
      tokens.push_back(Token(Token::Type::MOD, "%"));
      advance();
    } else if (currentChar == '<') {
      tokens.push_back(Token(Token::Type::LESS, "<"));
      advance();
    } else if (currentChar == '>') {
      tokens.push_back(Token(Token::Type::GREATER, ">"));
      advance();
    } else if (currentChar == ';') {
      tokens.push_back(Token(Token::Type::SEMICOLON, ";"));
      advance();
    }
    // else if (currentChar == '(') {
    //   tokens.push_back(Token(Token::Type::LEFT_BRACKET, "("));
    //   advance();
    // } else if (currentChar == ')') {
    //   tokens.push_back(Token(Token::Type::RIGHT_BRACKET, ")"));
    //   advance();
    // } else if (currentChar == '[') {
    //   tokens.push_back(Token(Token::Type::CALL_FUN_OPEN, "["));
    //   advance();
    // } else if (currentChar == ']') {
    //   tokens.push_back(Token(Token::Type::CALL_FUN_CLOSE, "]"));
    //   advance();
    // } else if (currentChar == ',') {
    //   tokens.push_back(Token(Token::Type::COMMA, ","));
    //   advance();
    // }
    else if (currentChar == '(') {
      if (!tokens.empty() && (tokens.back().type == Token::Type::IF ||
                              tokens.back().type == Token::Type::WHILE ||
                              tokens.back().type == Token::Type::PRINT ||
                              tokens.back().type == Token::Type::IDENTIFIER)) {
        tokens.push_back(Token(Token::Type::LEFT_PAREN, "("));  // Обычные скобки
        } else {
          throw std::runtime_error("Unexpected '(' - Use '{' for code blocks.");
        }
      advance();
    }
    else if (currentChar == ')') {
      tokens.push_back(Token(Token::Type::RIGHT_PAREN, ")"));
      advance();
    }
    else if (currentChar == '{') {
      tokens.push_back(Token(Token::Type::BLOCK_OPEN, "{"));
      advance();
    }
    else if (currentChar == '}') {
      tokens.push_back(Token(Token::Type::BLOCK_CLOSE, "}"));
      advance();
    }
    else if (currentChar == '[') {
      tokens.push_back(Token(Token::Type::LEFT_BRACKET, "["));
      advance();
    }
    else if (currentChar == ']') {
      tokens.push_back(Token(Token::Type::RIGHT_BRACKET, "]"));
      advance();
    }
    else if (currentChar == '!') {
      advance();
      if (currentChar == '=') {
        tokens.push_back(Token(Token::Type::NOT_EQUALS, "!="));
        advance();
      } else {
        throw std::runtime_error("Unexpected character: !");
      }
    } else {
      throw std::runtime_error("Unexpected character: " +
                               std::string(1, currentChar));
    }
  }
  return tokens;
}

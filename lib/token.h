#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
 public:
  enum class Type {
    LET,
    IDENTIFIER,
    NUMBER,
    EQUAL,
    PLUS,
    PRINT,
    SEMICOLON,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    COMMA,
    MINUS,
    STAR,
    LESS,
    GREATER,
    EQUALS,
    NOT_EQUALS,
    IF,
    LOOP,
    FUN,
    RETURN,
    NEW,
    WRITE_INDEX,
    STORE_ARRAY_VAR,
    CALL_FUN_OPEN,
    CALL_FUN_CLOSE,
    MOD
  };

  Type type;
  std::string value;

  Token(Type type, const std::string& value);
  std::string toString() const;
};

#endif  // TOKEN_H

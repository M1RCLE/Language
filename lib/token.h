#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
    enum class Type {
        VAR,
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
        MULT,
        LESS,
        GREATER,
        EQUALS,
        NOT_EQUALS,
        IF,
        WHILE,
        DEF,
        RETURN,
        NEW,
        WRITE_INDEX,
        STORE_ARRAY_VAR,
        CALL_FUN_OPEN,
        CALL_FUN_CLOSE,
        LEFT_PAREN,
        RIGHT_PAREN,
        BLOCK_OPEN,
        BLOCK_CLOSE,
        MOD
    };

    Type type;
    std::string value;

    Token(Type type, const std::string &value);

    std::string toString() const;
};

#endif  // TOKEN_H

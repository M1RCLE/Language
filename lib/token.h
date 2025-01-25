#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
    enum class Type {
        BLOCK_CLOSE,
        BLOCK_OPEN,
        CALL_FUN_CLOSE,
        CALL_FUN_OPEN,
        COMMA,
        DEF,
        EQUAL,
        EQUALS,
        GREATER,
        IDENTIFIER,
        IF,
        LEFT_BRACKET,
        LEFT_ELEMENT,
        LESS,
        MINUS,
        MOD,
        MULT,
        NEW,
        NOT_EQUALS,
        NUMBER,
        PLUS,
        PRINT,
        RETURN,
        RIGHT_BRACKET,
        RIGHT_ELEMENT,
        SEMICOLON,
        STORE_ARRAY_VAR,
        VAR,
        WHILE,
        WRITE_INDEX,
    };

    Type type;
    std::string value;

    Token(Type type, const std::string &value);

    std::string toString() const;
};

#endif  // TOKEN_H

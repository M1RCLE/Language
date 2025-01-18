#include "token.h"

Token::Token(Type type, const std::string& value) : type(type), value(value) {}

std::string Token::toString() const {
  return "Token{type=" + std::to_string(static_cast<int>(type)) + ", value='" +
         value + "'}";
}

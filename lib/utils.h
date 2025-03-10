#ifndef UTILS_H
#define UTILS_H

#include <any>
#include <string>

template <typename T>
static bool compareAny(const std::any &a, const std::any &b) {
  if (a.type() != b.type()) {
    return false;
  }

  if (a.type() == typeid(T)) {
    T value1 = std::any_cast<T>(a);
    T value2 = std::any_cast<T>(b);
    return value1 == value2;
  }

  return false;
}

static bool compareAnyValues(const std::any &a, const std::any &b) {
  if (a.type() == b.type()) {
    if (a.type() == typeid(int)) {
      return compareAny<int>(a, b);
    } else if (a.type() == typeid(double)) {
      return compareAny<double>(a, b);
    } else if (a.type() == typeid(std::string)) {
      return compareAny<std::string>(a, b);
    } else if (a.type() == typeid(long long)) {
      return compareAny<long long>(a, b);
    }
  }
  return false;
}

static bool is_number(const std::string &s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

#endif
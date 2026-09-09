#pragma once

#include <cctype>
#include <iostream>
#include <string>

class LowerCaseInputStream  {
private:
  std::istream &in_;

public:
  LowerCaseInputStream(std::istream &in) : in_(in) {}
  
  int read() {
    int c = in_.get();

    if (c == std::char_traits<char>::eof())
      return c;

    return std::tolower(static_cast<unsigned char>(c));
  }
};

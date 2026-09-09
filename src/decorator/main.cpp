#include <iostream>

#include "beverage_impl.hpp"
#include "condiment_impl.hpp"
#include "lowercase_input_stream.hpp"

inline void get_beverage_description(Beverage &beverage) {
  std::cout << beverage.get_description() << " $" << beverage.cost() << "\n";
}

int main() {
  Beverage *beverage = new Espresso();

  get_beverage_description(*beverage);
  
  Beverage *beverage_2 = new DarkRoast();
  beverage_2 = new Mocha(*beverage_2);
  beverage_2 = new Mocha(*beverage_2);
  beverage_2 = new Whip(*beverage_2);

  get_beverage_description(*beverage_2);

  std::cout << "Enter string: ";
  LowerCaseInputStream lower(std::cin);

  int c;
  while ((c = lower.read()) != EOF) {
    std::cout << static_cast<char>(c);
  }

  return 0;
}

#pragma once

#include "beverage.hpp"

class CondimentDecorator : public Beverage {
protected:
  Beverage &beverage_;
public:
  CondimentDecorator(Beverage &beverage) : beverage_(beverage) {}
  std::string get_description() const override = 0;
};

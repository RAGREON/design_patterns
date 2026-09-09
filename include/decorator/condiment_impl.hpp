#pragma once

#include "beverage.hpp"
#include "condiment_decorator.hpp"

class SteamedMilk : public CondimentDecorator {
public:
  SteamedMilk(Beverage &beverage) : CondimentDecorator(beverage) {} 

  std::string get_description() const override {
    return beverage_.get_description() + ", SteamedMilk";
  }

  double cost() const override {
    return beverage_.cost() + 0.10f;
  }
};

class Mocha : public CondimentDecorator {
public:
  Mocha(Beverage &beverage) : CondimentDecorator(beverage) {} 

  std::string get_description() const override {
    return beverage_.get_description() + ", Mocha";
  }

  double cost() const override {
    return beverage_.cost() + 0.20f;
  }
};

class Soy : public CondimentDecorator {
public:
  Soy(Beverage &beverage) : CondimentDecorator(beverage) {} 

  std::string get_description() const override {
    return beverage_.get_description() + ", Soy";
  }

  double cost() const override {
    return beverage_.cost() + 0.15f;
  }
};

class Whip : public CondimentDecorator {
public:
  Whip(Beverage &beverage) : CondimentDecorator(beverage) {} 

  std::string get_description() const override {
    return beverage_.get_description() + ", Whip";
  }

  double cost() const override {
    return beverage_.cost() + 0.10f;
  }
};

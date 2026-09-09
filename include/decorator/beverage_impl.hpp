#pragma once

#include "beverage.hpp"

class Espresso : public Beverage {
public:
  Espresso() {
    description = "Espresso";
  }

  double cost() const override {
    return 1.99f;
  }
};

class HouseBlend : public Beverage {
public:
  HouseBlend() {
    description = "House Blend Coffee";
  }

  double cost() const override {
    return 0.89f;
  }
};

class Decaf : public Beverage {
public:
  Decaf() {
    description = "Decaf Coffee";
  }

  double cost() const override {
    return 1.05f;
  }
};

class DarkRoast : public Beverage {
public:
  DarkRoast() {
    description = "Dark Roast Coffee";
  }

  double cost() const override {
    return 0.99f;
  }
};

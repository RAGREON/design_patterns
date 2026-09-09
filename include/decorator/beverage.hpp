#pragma once

#include <string>

class Beverage {
protected:
  std::string description = "Unknown Beverage";
  
public:
  virtual std::string get_description() const { return description; }
  virtual double cost() const = 0;
  virtual ~Beverage() = default;
};

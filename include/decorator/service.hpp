#pragma once

#include <iostream>

class IService {
public:
  virtual void execute() = 0;
  virtual ~IService() = default;
};

class Service : public IService {
public:
  void execute() override {
    std::cout << "Executing service...\n";
  }
};

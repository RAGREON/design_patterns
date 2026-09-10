#pragma once

#include <iostream>

#include "service.hpp"

class LoggingService : public IService {
protected:
  IService &service_;

public:
  LoggingService(IService &service) : service_(service) {}

  void execute() override {
    std::cout << "Starting Service:\n";

    service_.execute();

    std::cout << "Finished executing service\n";
  }
};

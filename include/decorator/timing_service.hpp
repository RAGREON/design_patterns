#pragma once

#include <chrono>
#include <iostream>

#include "service.hpp"

using namespace std::chrono;

class TimingService : public IService {
protected:
  IService &service_;

public:
  TimingService(IService &service) : service_(service) {}

  void execute() override {
    auto start = high_resolution_clock::now();
    service_.execute();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    std::cout << "Time taken: " << duration.count() << "us\n";
  }
};

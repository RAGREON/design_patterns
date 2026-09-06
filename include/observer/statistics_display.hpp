#pragma once

#include <iostream>
#include <stdexcept>

#include "observer.hpp"
#include "display_element.hpp"
#include "weather_data.hpp"
#include "helpers.hpp"

class StatisticsDisplay : public IObserver, public IDisplayElement {
private:
  float minTemp_;
  float maxTemp_;
  float avgTemp_;

  int count_;

  WeatherData *weatherData_;

public:
  StatisticsDisplay(WeatherData &weatherData) {
    weatherData_ = &weatherData;
    weatherData_->add_observer(*this);

    minTemp_ = 0.0f;
    maxTemp_ = 0.0f;
    avgTemp_ = 0.0f;

    count_ = 0;
  }

  void update() override {
    float temperature = weatherData_->get_temperature();

    if (count_ == 0) {
      minTemp_ = temperature;
      maxTemp_ = temperature; 
      avgTemp_ = temperature;
    }
    else {
      minTemp_ = std::min(minTemp_, temperature);
      maxTemp_ = std::max(maxTemp_, temperature);
      avgTemp_ = (count_ * avgTemp_ + temperature) / (count_ + 1);
    }

    count_++;

    display();
  }

  void subscribe(ISubject &o) override {
    weatherData_ = dynamic_cast<WeatherData*>(&o); 
    
    if (weatherData_ == nullptr) {
      throw std::invalid_argument("ISubject is not WeatherData");
    }

    unsubscribe();

    weatherData_->add_observer(*this);
  }

  void unsubscribe() override { 
    weatherData_->remove_observer(*this);
    weatherData_ = nullptr;
  }

  void display() override {
    std::cout << "Statistics of " 
              << weatherData_->get_location() << ":\n";

    print_float_with_precision("Min Temp", minTemp_, "C");
    print_float_with_precision("Max Temp", maxTemp_, "C");
    print_float_with_precision("Avg Temp", avgTemp_, "C");
  }

  ~StatisticsDisplay() {
    if (weatherData_ != nullptr) 
      weatherData_->remove_observer(*this);
  }
};

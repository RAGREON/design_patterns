#pragma once

#include <iostream>

#include "observer.hpp"
#include "display_element.hpp"
#include "weather_data.hpp"
#include "helpers.hpp"

class CurrentConditionsDisplay : public IObserver, public IDisplayElement {
private:
  float temperature_;
  float humidity_;

  WeatherData *weatherData_;

public:
  CurrentConditionsDisplay(WeatherData &weatherData) {
    weatherData_ = &weatherData;
    weatherData_->add_observer(*this);
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

  void update() override {
    temperature_ = weatherData_->get_temperature(); 
    humidity_ = weatherData_->get_humidity();
    
    display();
  }

  void display() override {
    std::cout << "Current weather conditions of " 
              << weatherData_->get_location() << ":\n";

    print_float_with_precision("Temperature", temperature_, "C");
    print_float_with_precision("Humidity", humidity_, "%");
  }

  ~CurrentConditionsDisplay() {
    if (weatherData_ != nullptr)
      weatherData_->remove_observer(*this);
  }
};

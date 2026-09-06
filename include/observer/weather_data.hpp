#pragma once

#include <vector>

#include "subject.hpp"
#include "observer.hpp"

class WeatherData : public ISubject {
private:
  std::string location_;

  float temperature_;
  float humidity_;
  float pressure_;

  std::vector<IObserver*> observers_;

public:
  WeatherData(const std::string &location) : location_(location) {}

  void add_observer(IObserver &o) override {
    observers_.push_back(&o);
  }
  
  void remove_observer(IObserver &o) override {
    for (auto it = observers_.begin(); it != observers_.end(); it++) {
      if (*it == &o) {
        observers_.erase(it);
        return;
      }
    }
  }

  void notify_observers() override {
    for (IObserver* i : observers_) {
      i->update();
    }
  }

  std::string get_location() const { return location_; }
  float get_temperature() const { return temperature_; }
  float get_humidity() const { return humidity_; }
  float get_pressure() const { return pressure_; }

  void measurements_changed() {
    notify_observers();
  }

  void set_measurements(float temperature, float humidity, float pressure) {
    temperature_ = temperature;
    humidity_ = humidity;
    pressure_ = pressure;

    measurements_changed();
  }

  ~WeatherData() {
    for (IObserver *i : observers_) {
      i->unsubscribe(); 
    }
  }
};

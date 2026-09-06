#include <vector>

#include "weather_data.hpp"
#include "current_conditions_display.hpp"
#include "statistics_display.hpp"

int main() {
  std::vector<WeatherData> wd = {
    WeatherData("Biratnagar"),
    WeatherData("Kathmandu")
  };

  IObserver *currentConditions = new CurrentConditionsDisplay(wd[0]); 
  IObserver *statistics = new StatisticsDisplay(wd[0]);

  wd[0].set_measurements(12.0f, 13.3f, 5.0f);

  currentConditions->unsubscribe();
  currentConditions->subscribe(wd[1]);

  wd[1].set_measurements(10.0f, 23.35f, 3.0f);

  statistics->unsubscribe();
  statistics->subscribe(wd[1]);

  wd[0].set_measurements(14.0f, 13.3f, 5.0f);

  wd[1].set_measurements(15.0f, 33.35f, 2.4f);

  return 0;
}

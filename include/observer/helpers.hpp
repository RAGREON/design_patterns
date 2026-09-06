#pragma once

#include <iostream>
#include <iomanip>

void print_float_with_precision(std::string label, float value, std::string suffix, int precision = 1) {
    std::cout << "  - "
              << std::left << std::setw(20) << label 
              << ": " << std::fixed << std::setprecision(precision) << value << suffix << "\n";
}

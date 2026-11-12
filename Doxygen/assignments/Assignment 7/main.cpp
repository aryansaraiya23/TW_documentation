/**
 * @file main.cpp
 * @brief Application entry point.
 */
#include <iostream>
#include "CalculationEngine.h"

/**
 * @brief Runs a sample calculation.
 * @return 0 on success.
 */
int main() {
    CalculationEngine engine;
    std::cout << "2^10 = " << engine.power_calculation(2, 10) << std::endl;
    return 0;
}

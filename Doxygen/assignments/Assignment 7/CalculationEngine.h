/**
 * @file CalculationEngine.h
 * @brief Defines a class for mathematical operations.
 */
#ifndef CALCULATIONENGINE_H
#define CALCULATIONENGINE_H

#include "Logger.h"

/**
 * @class CalculationEngine
 * @brief Performs simple mathematical operations.
 *
 * @details Every operation writes a message using the Logger class,
 * so the user can see which calculations were performed.
 */
class CalculationEngine {
public:
    /**
     * @brief Calculates base raised to the power of exponent.
     *
     * @param base     The base number.
     * @param exponent The exponent (a non-negative whole number).
     * @return The value of base raised to the power exponent.
     *
     * @todo Add support for negative exponents.
     */
    double power_calculation(double base, int exponent) {
        logger_.log("Calculating power");
        double result = 1.0;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }

private:
    Logger logger_{"CalcEngine"}; /**< Logger used by this class. */
};

#endif

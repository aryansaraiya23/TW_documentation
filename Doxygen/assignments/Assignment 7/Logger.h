/**
 * @file Logger.h
 * @brief Defines a simple Logging class.
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

/**
 * @mainpage Calculation Engine Project
 *
 * This project is a small multi-file C++ program. It contains:
 * - Logger.h: a simple class that prints log messages.
 * - CalculationEngine.h: a class for math operations that uses the Logger.
 * - main.cpp: the application entry point.
 *
 * The documentation is generated using Doxygen.
 */

/**
 * @enum LogLevel
 * @brief Severity level of a log message.
 */
enum LogLevel {
    INFO,    /**< General information message. */
    WARNING, /**< Something unexpected, but the program can continue. */
    ERROR    /**< A serious problem occurred. */
};

/**
 * @class Logger
 * @brief A simple class that prints messages to the console.
 */
class Logger {
public:
    /**
     * @brief Constructs a Logger.
     * @param name   Name printed at the start of every message.
     * @param level  Level used when log() is called without a level.
     */
    Logger(const std::string& name, LogLevel level = INFO)
        : name_(name), level_(level) {}

    /**
     * @brief Prints a message to the console.
     * @param message The text to print.
     */
    void log(const std::string& message) const {
        const char* labels[] = {"INFO", "WARNING", "ERROR"};
        std::cout << "[" << name_ << "] " << labels[level_] << ": "
                  << message << std::endl;
    }

private:
    std::string name_; /**< Name of the logger. */
    LogLevel level_;   /**< Default level of the logger. */
};

#endif

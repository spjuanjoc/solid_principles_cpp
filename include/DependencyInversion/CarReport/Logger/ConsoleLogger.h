/**
 * @file ConsoleLogger.h
 *
 * @brief Declaration of the ConsoleLogger class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef DEPENDENCY_INVERSION_LOGGER_CONSOLELOGGER_H
#define DEPENDENCY_INVERSION_LOGGER_CONSOLELOGGER_H

#include "ILogger.h"

#include <iostream>
#include <string>

namespace DependencyInversion
{

class ConsoleLogger : public virtual ILogger
{
public:
  ConsoleLogger()                                = default;
  ~ConsoleLogger() override                      = default;
  ConsoleLogger(const ConsoleLogger&)            = default;
  ConsoleLogger(ConsoleLogger&&)                 = default;
  ConsoleLogger& operator=(const ConsoleLogger&) = default;
  ConsoleLogger& operator=(ConsoleLogger&&)      = default;

  void writeEntry(const std::string& message) override;
};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_LOGGER_CONSOLELOGGER_H
